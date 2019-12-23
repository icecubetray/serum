#ifndef __SERUM_CORE_SANITY_H
#define __SERUM_CORE_SANITY_H




#include <errno.h>




#define SERUM_OK							0
#define SERUM_ERRNO							1	/*!< \hideinitializer \brief Returned when errno describes the error perfectly fine. */
#define SERUM_NULLPTR						2	/*!< \hideinitializer \brief Nullpointer encountered where NULL was not expected. */
#define SERUM_RANGE							3	/*!< \hideinitializer \brief Value is out of the expected range. */




#define SERUM_RETERRNOIFEXPR(__expr, __ret, __errno)	\
	if ((__expr)) {										\
		errno = (__errno);								\
		return (__ret);									\
	}

#define SERUM_CHECK_NULLPTR(__ptr)			SERUM_RETERRNOIFEXPR(((__ptr) == NULL), SERUM_NULLPTR, ENOMSG)
#define SERUM_CHECK_RANGE(__val, _lb, _ub)	SERUM_RETERRNOIFEXPR(( ( (__val) < (_lb) ) || ( (__val) > (_ub) ) ), SERUM_RANGE, ENOMSG);




#endif
