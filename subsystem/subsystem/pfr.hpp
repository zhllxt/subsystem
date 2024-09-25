#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <functional>
#include <type_traits>

template<typename BaseT, typename... Args>
class class_factory
{
private:
		class_factory() {}
	~class_factory() {}

public:
	static class_factory<BaseT, Args...>& instance()
	{
		static class_factory<BaseT, Args...> inst{};
		return inst;
	}

	bool regist(std::string name, std::function<BaseT*(Args&&... args)> fn)
	{
		if (!fn)
			return(false);

		return create_functions_.emplace(std::move(name), std::move(fn)).second;
	}

	BaseT* create(const std::string& name, Args&&... args)
	{
		auto iter = create_functions_.find(name);
		if (iter == create_functions_.end())
		{
			return (nullptr);
		}
		else
		{
			return ((iter->second)(std::forward<Args>(args)...));
		}
	}

	template<class Function>
	void for_each(Function&& callback) noexcept
	{
		for (const auto& [name, func] : create_functions_)
		{
			callback(name, func);
		}
	}

	std::function<BaseT* (Args&&...)>* find(const std::string& name)
	{
		auto it = create_functions_.find(name);
		return it == create_functions_.end() ? nullptr : std::addressof(it->second);
	}

	inline std::size_t size() const noexcept
	{
		return create_functions_.size();
	}

	inline bool empty() const noexcept
	{
		return create_functions_.empty();
	}

private:
	std::unordered_map<std::string, std::function<BaseT*(Args&&...)>> create_functions_;
};

template<typename BaseT, typename T, typename ...Args>
class base_dynamic_creator
{
public:
	struct registor
	{
		registor()
		{
			std::string name = typeid(T).name();
			if (name.find("struct ") == 0)
				name.erase(0, std::strlen("struct "));
			class_factory<BaseT, Args...>::instance().regist(std::move(name), create);
		}
		inline void makesure_construct() const noexcept { };
	};

	explicit base_dynamic_creator() noexcept
	{
		registor_.makesure_construct();
	}
	virtual ~base_dynamic_creator() noexcept
	{
		registor_.makesure_construct();
	};

private:
	static BaseT* create(Args&&... args)
	{
		return (new T(std::forward<Args>(args)...));
	}

private:
	static inline registor registor_{};
};

template<typename BaseT, typename T, typename ...Args>
using dynamic_creator = base_dynamic_creator<BaseT, T, Args...>;

template<typename BaseT>
class create_helper
{
public:
	// dont use Args&&... args
	// it will cause issue like this:
	// int i = 2;
	// create("dog", i);
	// the i will be parsed as int&
	template<typename ...Args>
	static inline BaseT* create(const std::string& name, Args... args)
	{
		return (class_factory<BaseT, Args...>::instance().create(
			name, std::move(args)...));
	}
};

template<typename BaseT>
class create_helper<BaseT*>
{
public:
	template<typename ...Args>
	static inline BaseT* create(const std::string& name, Args... args)
	{
		return (class_factory<BaseT, Args...>::instance().create(
			name, std::move(args)...));
	}
};

template<typename BaseT>
class create_helper<std::shared_ptr<BaseT>>
{
public:
	template<typename ...Args>
	static inline std::shared_ptr<BaseT> create(const std::string& name, Args... args)
	{
		return std::shared_ptr<BaseT>(class_factory<BaseT, Args...>::instance().create(
			name, std::move(args)...));
	}
};

template<typename BaseT>
class create_helper<std::unique_ptr<BaseT>>
{
public:
	template<typename ...Args>
	static inline std::unique_ptr<BaseT> create(const std::string& name, Args... args)
	{
		return std::unique_ptr<BaseT>(class_factory<BaseT, Args...>::instance().create(
			name, std::move(args)...));
	}
};
