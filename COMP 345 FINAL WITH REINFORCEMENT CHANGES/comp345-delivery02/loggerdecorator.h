// game logger decorator. Concrete decorators will inherit this class. There are only two types
// of decorators: a decorator for selective player logging, and another decorator for selective phase
// logging.

#pragma once

#include "logger.h"

class loggerdecorator : public logger {
	// nothing here
};