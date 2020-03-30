#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.resources"), aligned (8)))
#else
# define SECTION
#endif

#ifdef _MSC_VER
static const SECTION union { const guint8 data[633]; const double alignment; void * const ptr;}  resources_resource_data = { {
  0107, 0126, 0141, 0162, 0151, 0141, 0156, 0164, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0030, 0000, 0000, 0000, 0310, 0000, 0000, 0000, 0000, 0000, 0000, 0050, 0006, 0000, 0000, 0000, 
  0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0001, 0000, 0000, 0000, 0004, 0000, 0000, 0000, 
  0004, 0000, 0000, 0000, 0004, 0000, 0000, 0000, 0007, 0005, 0033, 0331, 0003, 0000, 0000, 0000, 
  0310, 0000, 0000, 0000, 0022, 0000, 0166, 0000, 0340, 0000, 0000, 0000, 0150, 0001, 0000, 0000, 
  0324, 0265, 0002, 0000, 0377, 0377, 0377, 0377, 0150, 0001, 0000, 0000, 0001, 0000, 0114, 0000, 
  0154, 0001, 0000, 0000, 0160, 0001, 0000, 0000, 0106, 0214, 0034, 0117, 0005, 0000, 0000, 0000, 
  0160, 0001, 0000, 0000, 0004, 0000, 0114, 0000, 0164, 0001, 0000, 0000, 0170, 0001, 0000, 0000, 
  0320, 0313, 0247, 0151, 0002, 0000, 0000, 0000, 0170, 0001, 0000, 0000, 0012, 0000, 0114, 0000, 
  0204, 0001, 0000, 0000, 0214, 0001, 0000, 0000, 0335, 0247, 0044, 0166, 0003, 0000, 0000, 0000, 
  0214, 0001, 0000, 0000, 0024, 0000, 0166, 0000, 0240, 0001, 0000, 0000, 0155, 0002, 0000, 0000, 
  0117, 0173, 0200, 0327, 0001, 0000, 0000, 0000, 0155, 0002, 0000, 0000, 0007, 0000, 0114, 0000, 
  0164, 0002, 0000, 0000, 0170, 0002, 0000, 0000, 0147, 0154, 0141, 0162, 0145, 0141, 0055, 0166, 
  0145, 0162, 0164, 0145, 0170, 0056, 0147, 0154, 0163, 0154, 0000, 0000, 0000, 0000, 0000, 0000, 
  0170, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0043, 0166, 0145, 0162, 0163, 0151, 0157, 0156, 
  0040, 0063, 0063, 0060, 0012, 0012, 0154, 0141, 0171, 0157, 0165, 0164, 0050, 0154, 0157, 0143, 
  0141, 0164, 0151, 0157, 0156, 0040, 0075, 0040, 0060, 0051, 0040, 0151, 0156, 0040, 0166, 0145, 
  0143, 0064, 0040, 0160, 0157, 0163, 0151, 0164, 0151, 0157, 0156, 0073, 0012, 0165, 0156, 0151, 
  0146, 0157, 0162, 0155, 0040, 0155, 0141, 0164, 0064, 0040, 0155, 0166, 0160, 0073, 0012, 0012, 
  0166, 0157, 0151, 0144, 0040, 0155, 0141, 0151, 0156, 0050, 0051, 0040, 0173, 0012, 0040, 0040, 
  0147, 0154, 0137, 0120, 0157, 0163, 0151, 0164, 0151, 0157, 0156, 0040, 0075, 0040, 0155, 0166, 
  0160, 0040, 0052, 0040, 0160, 0157, 0163, 0151, 0164, 0151, 0157, 0156, 0073, 0012, 0175, 0012, 
  0000, 0000, 0050, 0165, 0165, 0141, 0171, 0051, 0057, 0000, 0000, 0000, 0005, 0000, 0000, 0000, 
  0163, 0162, 0143, 0057, 0003, 0000, 0000, 0000, 0162, 0145, 0163, 0157, 0165, 0162, 0143, 0145, 
  0163, 0057, 0000, 0000, 0004, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0147, 0154, 0141, 0162, 
  0145, 0141, 0055, 0146, 0162, 0141, 0147, 0155, 0145, 0156, 0164, 0056, 0147, 0154, 0163, 0154, 
  0275, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0043, 0166, 0145, 0162, 0163, 0151, 0157, 0156, 
  0040, 0063, 0063, 0060, 0012, 0012, 0157, 0165, 0164, 0040, 0166, 0145, 0143, 0064, 0040, 0157, 
  0165, 0164, 0160, 0165, 0164, 0103, 0157, 0154, 0157, 0162, 0073, 0012, 0012, 0166, 0157, 0151, 
  0144, 0040, 0155, 0141, 0151, 0156, 0050, 0051, 0040, 0173, 0012, 0040, 0040, 0146, 0154, 0157, 
  0141, 0164, 0040, 0154, 0145, 0162, 0160, 0126, 0141, 0154, 0040, 0075, 0040, 0147, 0154, 0137, 
  0106, 0162, 0141, 0147, 0103, 0157, 0157, 0162, 0144, 0056, 0171, 0040, 0057, 0040, 0065, 0060, 
  0060, 0056, 0060, 0146, 0073, 0012, 0012, 0040, 0040, 0157, 0165, 0164, 0160, 0165, 0164, 0103, 
  0157, 0154, 0157, 0162, 0040, 0075, 0040, 0155, 0151, 0170, 0050, 0166, 0145, 0143, 0064, 0050, 
  0061, 0056, 0060, 0146, 0054, 0040, 0060, 0056, 0070, 0065, 0146, 0054, 0040, 0060, 0056, 0063, 
  0065, 0146, 0054, 0040, 0061, 0056, 0060, 0146, 0051, 0054, 0040, 0166, 0145, 0143, 0064, 0050, 
  0060, 0056, 0062, 0146, 0054, 0040, 0060, 0056, 0062, 0146, 0054, 0040, 0060, 0056, 0062, 0146, 
  0054, 0040, 0061, 0056, 0060, 0146, 0051, 0054, 0040, 0154, 0145, 0162, 0160, 0126, 0141, 0154, 
  0051, 0073, 0012, 0175, 0012, 0000, 0000, 0050, 0165, 0165, 0141, 0171, 0051, 0147, 0154, 0141, 
  0162, 0145, 0141, 0057, 0002, 0000, 0000, 0000
} };
#else /* _MSC_VER */
static const SECTION union { const guint8 data[633]; const double alignment; void * const ptr;}  resources_resource_data = {
  "\107\126\141\162\151\141\156\164\000\000\000\000\000\000\000\000"
  "\030\000\000\000\310\000\000\000\000\000\000\050\006\000\000\000"
  "\000\000\000\000\000\000\000\000\001\000\000\000\004\000\000\000"
  "\004\000\000\000\004\000\000\000\007\005\033\331\003\000\000\000"
  "\310\000\000\000\022\000\166\000\340\000\000\000\150\001\000\000"
  "\324\265\002\000\377\377\377\377\150\001\000\000\001\000\114\000"
  "\154\001\000\000\160\001\000\000\106\214\034\117\005\000\000\000"
  "\160\001\000\000\004\000\114\000\164\001\000\000\170\001\000\000"
  "\320\313\247\151\002\000\000\000\170\001\000\000\012\000\114\000"
  "\204\001\000\000\214\001\000\000\335\247\044\166\003\000\000\000"
  "\214\001\000\000\024\000\166\000\240\001\000\000\155\002\000\000"
  "\117\173\200\327\001\000\000\000\155\002\000\000\007\000\114\000"
  "\164\002\000\000\170\002\000\000\147\154\141\162\145\141\055\166"
  "\145\162\164\145\170\056\147\154\163\154\000\000\000\000\000\000"
  "\170\000\000\000\000\000\000\000\043\166\145\162\163\151\157\156"
  "\040\063\063\060\012\012\154\141\171\157\165\164\050\154\157\143"
  "\141\164\151\157\156\040\075\040\060\051\040\151\156\040\166\145"
  "\143\064\040\160\157\163\151\164\151\157\156\073\012\165\156\151"
  "\146\157\162\155\040\155\141\164\064\040\155\166\160\073\012\012"
  "\166\157\151\144\040\155\141\151\156\050\051\040\173\012\040\040"
  "\147\154\137\120\157\163\151\164\151\157\156\040\075\040\155\166"
  "\160\040\052\040\160\157\163\151\164\151\157\156\073\012\175\012"
  "\000\000\050\165\165\141\171\051\057\000\000\000\005\000\000\000"
  "\163\162\143\057\003\000\000\000\162\145\163\157\165\162\143\145"
  "\163\057\000\000\004\000\000\000\000\000\000\000\147\154\141\162"
  "\145\141\055\146\162\141\147\155\145\156\164\056\147\154\163\154"
  "\275\000\000\000\000\000\000\000\043\166\145\162\163\151\157\156"
  "\040\063\063\060\012\012\157\165\164\040\166\145\143\064\040\157"
  "\165\164\160\165\164\103\157\154\157\162\073\012\012\166\157\151"
  "\144\040\155\141\151\156\050\051\040\173\012\040\040\146\154\157"
  "\141\164\040\154\145\162\160\126\141\154\040\075\040\147\154\137"
  "\106\162\141\147\103\157\157\162\144\056\171\040\057\040\065\060"
  "\060\056\060\146\073\012\012\040\040\157\165\164\160\165\164\103"
  "\157\154\157\162\040\075\040\155\151\170\050\166\145\143\064\050"
  "\061\056\060\146\054\040\060\056\070\065\146\054\040\060\056\063"
  "\065\146\054\040\061\056\060\146\051\054\040\166\145\143\064\050"
  "\060\056\062\146\054\040\060\056\062\146\054\040\060\056\062\146"
  "\054\040\061\056\060\146\051\054\040\154\145\162\160\126\141\154"
  "\051\073\012\175\012\000\000\050\165\165\141\171\051\147\154\141"
  "\162\145\141\057\002\000\000\000" };
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
