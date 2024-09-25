#pragma once

#include "imodule.hpp"
#include "pfr.hpp"
#include "module_dependencies.hpp"

#include <map>

struct module_info
{
	std::string class_name{};
	std::shared_ptr<imodule> module_ptr{};
	std::size_t sort_index{};
};

struct module_mgr
{
    module_mgr()
    {
        class_factory<imodule>& factory = class_factory<imodule>::instance();

        factory.for_each([this](std::string class_name, const auto& create_func) mutable
        {
            modules.emplace_back(module_info{ class_name, std::shared_ptr<imodule>(create_func()), 0 });
        });

        std::vector<std::string> sorted_names = module_dependencies::instance().sort();

        for (auto& info : modules)
        {
            for (std::size_t i = 0; i < sorted_names.size(); i++)
            {
                if (info.class_name == sorted_names[i])
                {
                    info.sort_index = i;
                    break;
                }
            }
        }
    }

    bool init()
    {
	    for (auto& info : modules)
        {
            info.module_ptr->init();
        }

        return true;
    }

    bool start()
    {
        for (auto& info : modules)
        {
            info.module_ptr->start();
        }

        return true;
    }

    void stop()
    {
        for (auto& info : modules)
        {
            info.module_ptr->stop();
        }
    }

    void uninit()
    {
        for (auto& info : modules)
        {
            info.module_ptr->uninit();
        }
    }

    void sort(bool ascend)
    {
        std::sort(modules.begin(), modules.end(), [ascend](const auto& a, const auto& b)
        {
            if (ascend)
                return a.sort_index < b.sort_index;
            else
                return a.sort_index > b.sort_index;
        });
    }

    std::vector<module_info> modules;
};
