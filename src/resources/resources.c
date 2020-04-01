#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.resources"), aligned (8)))
#else
# define SECTION
#endif

#ifdef _MSC_VER
static const SECTION union { const guint8 data[441]; const double alignment; void * const ptr;}  resources_resource_data = { {
  0107, 0126, 0141, 0162, 0151, 0141, 0156, 0164, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0030, 0000, 0000, 0000, 0220, 0000, 0000, 0000, 0000, 0000, 0000, 0050, 0004, 0000, 0000, 0000, 
  0000, 0000, 0000, 0000, 0002, 0000, 0000, 0000, 0002, 0000, 0000, 0000, 0003, 0000, 0000, 0000, 
  0324, 0265, 0002, 0000, 0377, 0377, 0377, 0377, 0220, 0000, 0000, 0000, 0001, 0000, 0114, 0000, 
  0224, 0000, 0000, 0000, 0230, 0000, 0000, 0000, 0334, 0034, 0253, 0324, 0003, 0000, 0000, 0000, 
  0230, 0000, 0000, 0000, 0024, 0000, 0166, 0000, 0260, 0000, 0000, 0000, 0007, 0001, 0000, 0000, 
  0106, 0056, 0062, 0325, 0003, 0000, 0000, 0000, 0007, 0001, 0000, 0000, 0022, 0000, 0166, 0000, 
  0040, 0001, 0000, 0000, 0250, 0001, 0000, 0000, 0117, 0173, 0200, 0327, 0000, 0000, 0000, 0000, 
  0250, 0001, 0000, 0000, 0007, 0000, 0114, 0000, 0260, 0001, 0000, 0000, 0270, 0001, 0000, 0000, 
  0057, 0000, 0000, 0000, 0003, 0000, 0000, 0000, 0147, 0154, 0141, 0162, 0145, 0141, 0055, 0146, 
  0162, 0141, 0147, 0155, 0145, 0156, 0164, 0056, 0147, 0154, 0163, 0154, 0000, 0000, 0000, 0000, 
  0107, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0043, 0166, 0145, 0162, 0163, 0151, 0157, 0156, 
  0040, 0063, 0063, 0060, 0040, 0143, 0157, 0162, 0145, 0012, 0157, 0165, 0164, 0040, 0166, 0145, 
  0143, 0063, 0040, 0143, 0157, 0154, 0157, 0162, 0073, 0012, 0166, 0157, 0151, 0144, 0040, 0155, 
  0141, 0151, 0156, 0050, 0051, 0173, 0012, 0040, 0040, 0143, 0157, 0154, 0157, 0162, 0040, 0075, 
  0040, 0166, 0145, 0143, 0063, 0050, 0061, 0054, 0060, 0054, 0060, 0051, 0073, 0012, 0175, 0000, 
  0000, 0050, 0165, 0165, 0141, 0171, 0051, 0147, 0154, 0141, 0162, 0145, 0141, 0055, 0166, 0145, 
  0162, 0164, 0145, 0170, 0056, 0147, 0154, 0163, 0154, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0170, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0043, 0166, 0145, 0162, 0163, 0151, 0157, 0156, 
  0040, 0063, 0063, 0060, 0012, 0012, 0154, 0141, 0171, 0157, 0165, 0164, 0050, 0154, 0157, 0143, 
  0141, 0164, 0151, 0157, 0156, 0040, 0075, 0040, 0060, 0051, 0040, 0151, 0156, 0040, 0166, 0145, 
  0143, 0064, 0040, 0160, 0157, 0163, 0151, 0164, 0151, 0157, 0156, 0073, 0012, 0165, 0156, 0151, 
  0146, 0157, 0162, 0155, 0040, 0155, 0141, 0164, 0064, 0040, 0155, 0166, 0160, 0073, 0012, 0012, 
  0166, 0157, 0151, 0144, 0040, 0155, 0141, 0151, 0156, 0050, 0051, 0040, 0173, 0012, 0040, 0040, 
  0147, 0154, 0137, 0120, 0157, 0163, 0151, 0164, 0151, 0157, 0156, 0040, 0075, 0040, 0155, 0166, 
  0160, 0040, 0052, 0040, 0160, 0157, 0163, 0151, 0164, 0151, 0157, 0156, 0073, 0012, 0175, 0012, 
  0000, 0000, 0050, 0165, 0165, 0141, 0171, 0051, 0147, 0154, 0141, 0162, 0145, 0141, 0057, 0000, 
  0001, 0000, 0000, 0000, 0002, 0000, 0000, 0000
} };
#else /* _MSC_VER */
static const SECTION union { const guint8 data[441]; const double alignment; void * const ptr;}  resources_resource_data = {
  "\107\126\141\162\151\141\156\164\000\000\000\000\000\000\000\000"
  "\030\000\000\000\220\000\000\000\000\000\000\050\004\000\000\000"
  "\000\000\000\000\002\000\000\000\002\000\000\000\003\000\000\000"
  "\324\265\002\000\377\377\377\377\220\000\000\000\001\000\114\000"
  "\224\000\000\000\230\000\000\000\334\034\253\324\003\000\000\000"
  "\230\000\000\000\024\000\166\000\260\000\000\000\007\001\000\000"
  "\106\056\062\325\003\000\000\000\007\001\000\000\022\000\166\000"
  "\040\001\000\000\250\001\000\000\117\173\200\327\000\000\000\000"
  "\250\001\000\000\007\000\114\000\260\001\000\000\270\001\000\000"
  "\057\000\000\000\003\000\000\000\147\154\141\162\145\141\055\146"
  "\162\141\147\155\145\156\164\056\147\154\163\154\000\000\000\000"
  "\107\000\000\000\000\000\000\000\043\166\145\162\163\151\157\156"
  "\040\063\063\060\040\143\157\162\145\012\157\165\164\040\166\145"
  "\143\063\040\143\157\154\157\162\073\012\166\157\151\144\040\155"
  "\141\151\156\050\051\173\012\040\040\143\157\154\157\162\040\075"
  "\040\166\145\143\063\050\061\054\060\054\060\051\073\012\175\000"
  "\000\050\165\165\141\171\051\147\154\141\162\145\141\055\166\145"
  "\162\164\145\170\056\147\154\163\154\000\000\000\000\000\000\000"
  "\170\000\000\000\000\000\000\000\043\166\145\162\163\151\157\156"
  "\040\063\063\060\012\012\154\141\171\157\165\164\050\154\157\143"
  "\141\164\151\157\156\040\075\040\060\051\040\151\156\040\166\145"
  "\143\064\040\160\157\163\151\164\151\157\156\073\012\165\156\151"
  "\146\157\162\155\040\155\141\164\064\040\155\166\160\073\012\012"
  "\166\157\151\144\040\155\141\151\156\050\051\040\173\012\040\040"
  "\147\154\137\120\157\163\151\164\151\157\156\040\075\040\155\166"
  "\160\040\052\040\160\157\163\151\164\151\157\156\073\012\175\012"
  "\000\000\050\165\165\141\171\051\147\154\141\162\145\141\057\000"
  "\001\000\000\000\002\000\000\000" };
#endif /* !_MSC_VER */

static GStaticResource static_resource = { resources_resource_data.data, sizeof (resources_resource_data.data) - 1 /* nul terminator */, NULL, NULL, NULL };
extern GResource *resources_get_resource (void);
GResource *resources_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a sane way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#ifndef __GTK_DOC_IGNORE__

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
/* Visual studio 2008 and later has _Pragma */

#include <stdlib.h>

#define G_HAS_CONSTRUCTORS 1

/* We do some weird things to avoid the constructors being optimized
 * away on VS2015 if WholeProgramOptimization is enabled. First we
 * make a reference to the array from the wrapper to make sure its
 * references. Then we use a pragma to make sure the wrapper function
 * symbol is always included at the link stage. Also, the symbols
 * need to be extern (but not dllexport), even though they are not
 * really used from another object file.
 */

/* We need to account for differences between the mangling of symbols
 * for Win32 (x86) and x64 programs, as symbols on Win32 are prefixed
 * with an underscore but symbols on x64 are not.
 */
#ifdef _WIN64
#define G_MSVC_SYMBOL_PREFIX ""
#else
#define G_MSVC_SYMBOL_PREFIX "_"
#endif

#define G_DEFINE_CONSTRUCTOR(_func) G_MSVC_CTOR (_func, G_MSVC_SYMBOL_PREFIX)
#define G_DEFINE_DESTRUCTOR(_func) G_MSVC_DTOR (_func, G_MSVC_SYMBOL_PREFIX)

#define G_MSVC_CTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _wrapper(void) { _func(); g_slist_find (NULL,  _array ## _func); return 0; } \
  __pragma(comment(linker,"/include:" _sym_prefix # _func "_wrapper")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _wrapper;

#define G_MSVC_DTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _constructor(void) { atexit (_func); g_slist_find (NULL,  _array ## _func); return 0; } \
   __pragma(comment(linker,"/include:" _sym_prefix # _func "_constructor")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _constructor;

#elif defined (_MSC_VER)

#define G_HAS_CONSTRUCTORS 1

/* Pre Visual studio 2008 must use #pragma section */
#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (*p)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif

#endif /* __GTK_DOC_IGNORE__ */

#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(resource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(resource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(resource_destructor)
#endif
G_DEFINE_DESTRUCTOR(resource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void resource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void resource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}
