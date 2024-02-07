#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

static unsigned int
g_signal_new(const char *signal_name,
             uintptr_t itype,
	     int signal_flags,
	     unsigned int class_offset,
	     char *accum,
	     char *accum_data,
	     char *c_marshaller,
	     uintptr_t return_type,
	     unsigned int n_params,
	     ...);

static unsigned int
g_signal_newv(const char *signal_name,
              uintptr_t itype,
	      int signal_flags,
	      unsigned int class_offset,
	      char *accum,
	      char *accum_data,
	      char *c_marshaller,
	      uintptr_t return_type,
	      unsigned int n_params,
	      va_list args);


int
main(void)
{
	char *signal_name = "notify";

	g_signal_new(signal_name,
                     1,
	             1,
	             1,
	             NULL,
	             NULL,
	             NULL,
	             1,
	             1,
	             0x42);

	return 0;
}

static unsigned int
g_signal_new(const char *signal_name,
             uintptr_t itype,
	     int signal_flags,
	     unsigned int class_offset,
	     char *accum,
	     char *accum_data,
	     char *c_marshaller,
	     uintptr_t return_type,
	     unsigned int n_params,
	     ...)
{
	va_list args;

	va_start(args, n_params);

	g_signal_newv(signal_name,
                      itype,
	              signal_flags,
	              class_offset,
		      accum,
	              accum_data,
	              c_marshaller,
	              return_type,
	              n_params,
	              args);

	va_end(args);
	return 0;
}

static unsigned int
g_signal_newv(const char *signal_name,
              uintptr_t itype,
	      int signal_flags,
	      unsigned int class_offset,
	      char *accum,
	      char *accum_data,
	      char *c_marshaller,
	      uintptr_t return_type,
	      unsigned int n_params,
	      va_list args)
{
	uintptr_t val = va_arg(args, uintptr_t);

	printf("val = %X\n", (unsigned int) val);
	return 0;
}

