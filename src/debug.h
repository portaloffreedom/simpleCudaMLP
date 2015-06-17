#ifndef DEBUG_H
#define DEBUG_H

#ifdef NDEBUG

#define TRACING(code) ((void)0)
#else
#define TRACING(code) code
#endif

#endif // DEBUG_H
