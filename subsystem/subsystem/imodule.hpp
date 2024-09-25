#pragma once

#include <cstdio>

#include "pfr.hpp"

struct imodule
{
	virtual ~imodule() {}

	virtual bool init() = 0;
	virtual bool start() = 0;
	virtual void stop() = 0;
	virtual void uninit() = 0;
};
