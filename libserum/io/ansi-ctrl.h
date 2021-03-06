/******************************************************************************
**                                                                           **
**   The MIT License                                                         **
**                                                                           **
**   Copyright 2017-2018 icecubetray                                         **
**                                                                           **
**   Permission is hereby granted, free of charge, to any person             **
**   obtaining a copy of this software and associated documentation files    **
**   (the "Software"), to deal in the Software without restriction,          **
**   including without limitation the rights to use, copy, modify, merge,    **
**   publish, distribute, sublicense, and/or sell copies of the Software,    **
**   and to permit persons to whom the Software is furnished to do so,       **
**   subject to the following conditions:                                    **
**                                                                           **
**   The above copyright notice and this permission notice shall be          **
**   included in all copies or substantial portions of the Software.         **
**                                                                           **
**   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,         **
**   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF      **
**   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  **
**   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    **
**   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    **
**   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       **
**   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  **
**                                                                           **
******************************************************************************/


#ifndef __LS_IO_ANSI_H
#define __LS_IO_ANSI_H




#include "../core/setup/macros.h"




//! \cond LS_DOXYGEN_PRIVATE
#if (LS_ANSI_SUPPORT)
#	define __LS_ANSI(x)						x
#else
#	define __LS_ANSI(x)						""
#endif


#define __LS_ANSI_OPT_CC_NW(n, ...)			__LS_ANSI_OPT_CC_NI(n, __VA_ARGS__)
#define __LS_ANSI_OPT_CC_NI(n, ...)			__LS_ANSI_OPT_CC_ ## n (__VA_ARGS__)

#define __LS_ANSI_OPT_CC_0()
#define __LS_ANSI_OPT_CC_1(a)				a
#define __LS_ANSI_OPT_CC_2(a,b)				a LS_ANSI_ESCAPE_OPT b
#define __LS_ANSI_OPT_CC_3(a,b,c)			a LS_ANSI_ESCAPE_OPT b LS_ANSI_ESCAPE_OPT c
#define __LS_ANSI_OPT_CC_4(a,b,c,d)			a LS_ANSI_ESCAPE_OPT b LS_ANSI_ESCAPE_OPT c LS_ANSI_ESCAPE_OPT d
#define __LS_ANSI_OPT_CC_5(a,b,c,d,e)		a LS_ANSI_ESCAPE_OPT b LS_ANSI_ESCAPE_OPT c LS_ANSI_ESCAPE_OPT d LS_ANSI_ESCAPE_OPT e
#define __LS_ANSI_OPT_CC_6(a,b,c,d,e,f)		a LS_ANSI_ESCAPE_OPT b LS_ANSI_ESCAPE_OPT c LS_ANSI_ESCAPE_OPT d LS_ANSI_ESCAPE_OPT e LS_ANSI_ESCAPE_OPT f
#define __LS_ANSI_OPT_CC_7(a,b,c,d,e,f,g)	a LS_ANSI_ESCAPE_OPT b LS_ANSI_ESCAPE_OPT c LS_ANSI_ESCAPE_OPT d LS_ANSI_ESCAPE_OPT e LS_ANSI_ESCAPE_OPT f LS_ANSI_ESCAPE_OPT g
#define __LS_ANSI_OPT_CC_8(a,b,c,d,e,f,g,h)	a LS_ANSI_ESCAPE_OPT b LS_ANSI_ESCAPE_OPT c LS_ANSI_ESCAPE_OPT d LS_ANSI_ESCAPE_OPT e LS_ANSI_ESCAPE_OPT f LS_ANSI_ESCAPE_OPT g LS_ANSI_ESCAPE_OPT h
//! \endcond

//! \hideinitializer \brief Concatenates up to 8 ANSI options.
#define LS_ANSI_OPT_CONCAT(...)				__LS_ANSI_OPT_CC_NW(LS_NARG(__VA_ARGS__), __VA_ARGS__)




#define LS_ANSI_OPT_BOLDINTENSE				__LS_ANSI("1")		//!< \hideinitializer \brief ANSI style option: bold, increase color intensity
#define LS_ANSI_OPT_LESSINTENSE				__LS_ANSI("2")		//!< \hideinitializer \brief ANSI style option: reduce color intensity
#define LS_ANSI_OPT_BOLD_OFF_UNDERLINE_DBL	__LS_ANSI("21"		//!< \hideinitializer \brief ANSI style option: disable bold, double underlining

#define LS_ANSI_OPT_ITALIC					__LS_ANSI("3")		//!< \hideinitializer \brief ANSI style option: italic
#define LS_ANSI_OPT_FRAKTUR					__LS_ANSI("20"		//!< \hideinitializer \brief ANSI style option: fraktur
#define LS_ANSI_OPT_NO_ITALIC_NO_FRAKTUR	__LS_ANSI("23"		//!< \hideinitializer \brief ANSI style option: disable italic, disable fraktur

#define LS_ANSI_OPT_BLINK_SLOW				__LS_ANSI("5")		//!< \hideinitializer \brief ANSI style option: blink slowly
#define LS_ANSI_OPT_BLINK_RAPID				__LS_ANSI("6")		//!< \hideinitializer \brief ANSI style option: blink rapidly
#define LS_ANSI_OPT_BLINK_OFF				__LS_ANSI("25"		//!< \hideinitializer \brief ANSI style option: disable blink

#define LS_ANSI_OPT_CROSS_OUT				__LS_ANSI("9")		//!< \hideinitializer \brief ANSI style option: cross out
#define LS_ANSI_OPT_NO_CROSS_OUT			__LS_ANSI("29"		//!< \hideinitializer \brief ANSI style option: disable cross out
#define LS_ANSI_OPT_UNDERLINE_SINGLE		__LS_ANSI("4")		//!< \hideinitializer \brief ANSI style option: single underlining
#define LS_ANSI_OPT_NO_UNDERLINE			__LS_ANSI("24"		//!< \hideinitializer \brief ANSI style option: disable underlining
#define LS_ANSI_OPT_FRAME					__LS_ANSI("51"		//!< \hideinitializer \brief ANSI style option: frame
#define LS_ANSI_OPT_ENCIRCLE				__LS_ANSI("52"		//!< \hideinitializer \brief ANSI style option: encircle
#define LS_ANSI_OPT_OVERLINE				__LS_ANSI("53"		//!< \hideinitializer \brief ANSI style option: overline
#define LS_ANSI_OPT_NO_FRAME_NO_ENCIRCLE	__LS_ANSI("54"		//!< \hideinitializer \brief ANSI style option: no frame, no encircle
#define LS_ANSI_OPT_NO_OVERLINE				__LS_ANSI("55"		//!< \hideinitializer \brief ANSI style option: no overline

#define LS_ANSI_OPT_RESET					__LS_ANSI("0")		//!< \hideinitializer \brief ANSI style option: reset all styling
#define LS_ANSI_OPT_NORMAL					__LS_ANSI("22"		//!< \hideinitializer \brief ANSI style option: normal styling
#define LS_ANSI_OPT_NEGATIVE				__LS_ANSI("7")		//!< \hideinitializer \brief ANSI style option: negate styling
#define LS_ANSI_OPT_POSITIVE				__LS_ANSI("27"		//!< \hideinitializer \brief ANSI style option: positive styling
#define LS_ANSI_OPT_CONCEAL					__LS_ANSI("8")		//!< \hideinitializer \brief ANSI style option: conceal text
#define LS_ANSI_OPT_REVEAL					__LS_ANSI("28"		//!< \hideinitializer \brief ANSI style option: reveal text


// Color setup
//! \cond LS_DOXYGEN_PRIVATE
#define __LS_ANSI_CRF_NORMAL				__LS_ANSI("3")
#define __LS_ANSI_CRB_NORMAL				__LS_ANSI("4")
#define __LS_ANSI_CRF_BRIGHT				__LS_ANSI("9")
#define __LS_ANSI_CRB_BRIGHT				__LS_ANSI("10")

#define __LS_ANSI_COLOR_BLACK				__LS_ANSI("0")
#define __LS_ANSI_COLOR_RED					__LS_ANSI("1")
#define __LS_ANSI_COLOR_GREEN				__LS_ANSI("2")
#define __LS_ANSI_COLOR_YELLOW				__LS_ANSI("3")
#define __LS_ANSI_COLOR_BLUE				__LS_ANSI("4")
#define __LS_ANSI_COLOR_MAGENTA				__LS_ANSI("5")
#define __LS_ANSI_COLOR_CYAN				__LS_ANSI("6")
#define __LS_ANSI_COLOR_WHITE				__LS_ANSI("7")
#define __LS_ANSI_COLOR_DEFAULT				__LS_ANSI("9")

#define __LS_ANSI_MKCOLOR(r, c)				__LS_ANSI(r c)
#define __LS_ANSI_MKFCOLOR_NORMAL(c)		__LS_ANSI_MKCOLOR(__LS_ANSI_CRF_NORMAL, c)
#define __LS_ANSI_MKBCOLOR_NORMAL(c)		__LS_ANSI_MKCOLOR(__LS_ANSI_CRB_NORMAL, c)
#define __LS_ANSI_MKFCOLOR_BRIGHT(c)		__LS_ANSI_MKCOLOR(__LS_ANSI_CRF_BRIGHT, c)
#define __LS_ANSI_MKBCOLOR_BRIGHT(c)		__LS_ANSI_MKCOLOR(__LS_ANSI_CRB_BRIGHT, c)
#define __LS_ANSI_MKFCOLOR_DIMMED(c)		__LS_ANSI_MKFCOLOR_NORMAL(c) LS_ANSI_ESCAPE_OPT LS_ANSI_OPT_LESSINTENSE
#define __LS_ANSI_MKBCOLOR_DIMMED(c)		__LS_ANSI_MKBCOLOR_NORMAL(c) LS_ANSI_ESCAPE_OPT LS_ANSI_OPT_LESSINTENSE
//! \endcond


#define LS_ANSI_FG_RED						__LS_ANSI_MKFCOLOR_NORMAL(__LS_ANSI_COLOR_RED)		//!< \hideinitializer \brief ANSI color option: red foreground
#define LS_ANSI_BG_RED						__LS_ANSI_MKBCOLOR_NORMAL(__LS_ANSI_COLOR_RED)		//!< \hideinitializer \brief ANSI color option: red background
#define LS_ANSI_FG_BRIGHT_RED				__LS_ANSI_MKFCOLOR_BRIGHT(__LS_ANSI_COLOR_RED)		//!< \hideinitializer \brief ANSI color option: bright red foreground
#define LS_ANSI_BG_BRIGHT_RED				__LS_ANSI_MKBCOLOR_BRIGHT(__LS_ANSI_COLOR_RED)		//!< \hideinitializer \brief ANSI color option: bright red background
#define LS_ANSI_FG_TEAL						__LS_ANSI_MKFCOLOR_NORMAL(__LS_ANSI_COLOR_CYAN)		//!< \hideinitializer \brief ANSI color option: teal foreground
#define LS_ANSI_BG_TEAL						__LS_ANSI_MKBCOLOR_NORMAL(__LS_ANSI_COLOR_CYAN)		//!< \hideinitializer \brief ANSI color option: teal background
#define LS_ANSI_FG_CYAN						__LS_ANSI_MKFCOLOR_BRIGHT(__LS_ANSI_COLOR_CYAN)		//!< \hideinitializer \brief ANSI color option: cyan foreground
#define LS_ANSI_BG_CYAN						__LS_ANSI_MKBCOLOR_BRIGHT(__LS_ANSI_COLOR_CYAN)		//!< \hideinitializer \brief ANSI color option: cyan background
#define LS_ANSI_FG_BLUE						__LS_ANSI_MKFCOLOR_NORMAL(__LS_ANSI_COLOR_BLUE)		//!< \hideinitializer \brief ANSI color option: blue foreground
#define LS_ANSI_BG_BLUE						__LS_ANSI_MKBCOLOR_NORMAL(__LS_ANSI_COLOR_BLUE)		//!< \hideinitializer \brief ANSI color option: blue background
#define LS_ANSI_FG_BRIGHT_BLUE				__LS_ANSI_MKFCOLOR_BRIGHT(__LS_ANSI_COLOR_BLUE)		//!< \hideinitializer \brief ANSI color option: bright blue foreground
#define LS_ANSI_BG_BRIGHT_BLUE				__LS_ANSI_MKBCOLOR_BRIGHT(__LS_ANSI_COLOR_BLUE)		//!< \hideinitializer \brief ANSI color option: bright blue background
#define LS_ANSI_FG_BLACK					__LS_ANSI_MKFCOLOR_NORMAL(__LS_ANSI_COLOR_BLACK)	//!< \hideinitializer \brief ANSI color option: black foreground
#define LS_ANSI_BG_BLACK					__LS_ANSI_MKBCOLOR_NORMAL(__LS_ANSI_COLOR_BLACK)	//!< \hideinitializer \brief ANSI color option: black background
#define LS_ANSI_FG_DARK_GRAY				__LS_ANSI_MKFCOLOR_BRIGHT(__LS_ANSI_COLOR_BLACK)	//!< \hideinitializer \brief ANSI color option: dark gray foreground
#define LS_ANSI_BG_DARK_GRAY				__LS_ANSI_MKBCOLOR_BRIGHT(__LS_ANSI_COLOR_BLACK)	//!< \hideinitializer \brief ANSI color option: dark gray background
#define LS_ANSI_FG_GREEN					__LS_ANSI_MKFCOLOR_NORMAL(__LS_ANSI_COLOR_GREEN)	//!< \hideinitializer \brief ANSI color option: green foreground
#define LS_ANSI_BG_GREEN					__LS_ANSI_MKBCOLOR_NORMAL(__LS_ANSI_COLOR_GREEN)	//!< \hideinitializer \brief ANSI color option: green background
#define LS_ANSI_FG_LIME						__LS_ANSI_MKFCOLOR_BRIGHT(__LS_ANSI_COLOR_GREEN)	//!< \hideinitializer \brief ANSI color option: lime foreground
#define LS_ANSI_BG_LIME						__LS_ANSI_MKBCOLOR_BRIGHT(__LS_ANSI_COLOR_GREEN)	//!< \hideinitializer \brief ANSI color option: lime background
#define LS_ANSI_FG_GRAY						__LS_ANSI_MKFCOLOR_DIMMED(__LS_ANSI_COLOR_WHITE)	//!< \hideinitializer \brief ANSI color option: gray foreground
#define LS_ANSI_BG_GRAY						__LS_ANSI_MKBCOLOR_DIMMED(__LS_ANSI_COLOR_WHITE)	//!< \hideinitializer \brief ANSI color option: gray background
#define LS_ANSI_FG_BRIGHT_GRAY				__LS_ANSI_MKFCOLOR_NORMAL(__LS_ANSI_COLOR_WHITE)	//!< \hideinitializer \brief ANSI color option: bright gray foreground
#define LS_ANSI_BG_BRIGHT_GRAY				__LS_ANSI_MKBCOLOR_NORMAL(__LS_ANSI_COLOR_WHITE)	//!< \hideinitializer \brief ANSI color option: bright gray background
#define LS_ANSI_FG_WHITE					__LS_ANSI_MKFCOLOR_BRIGHT(__LS_ANSI_COLOR_WHITE)	//!< \hideinitializer \brief ANSI color option: white foreground
#define LS_ANSI_BG_WHITE					__LS_ANSI_MKBCOLOR_BRIGHT(__LS_ANSI_COLOR_WHITE)	//!< \hideinitializer \brief ANSI color option: white background
#define LS_ANSI_FG_ORANGE					__LS_ANSI_MKFCOLOR_NORMAL(__LS_ANSI_COLOR_YELLOW)	//!< \hideinitializer \brief ANSI color option: orange foreground
#define LS_ANSI_BG_ORANGE					__LS_ANSI_MKBCOLOR_NORMAL(__LS_ANSI_COLOR_YELLOW)	//!< \hideinitializer \brief ANSI color option: orange background
#define LS_ANSI_FG_YELLOW					__LS_ANSI_MKFCOLOR_BRIGHT(__LS_ANSI_COLOR_YELLOW)	//!< \hideinitializer \brief ANSI color option: yellow foreground
#define LS_ANSI_BG_YELLOW					__LS_ANSI_MKBCOLOR_BRIGHT(__LS_ANSI_COLOR_YELLOW)	//!< \hideinitializer \brief ANSI color option: yellow background
#define LS_ANSI_FG_MAGENTA					__LS_ANSI_MKFCOLOR_NORMAL(__LS_ANSI_COLOR_MAGENTA)	//!< \hideinitializer \brief ANSI color option: magenta foreground
#define LS_ANSI_BG_MAGENTA					__LS_ANSI_MKBCOLOR_NORMAL(__LS_ANSI_COLOR_MAGENTA)	//!< \hideinitializer \brief ANSI color option: magenta background
#define LS_ANSI_FG_PINK						__LS_ANSI_MKFCOLOR_BRIGHT(__LS_ANSI_COLOR_MAGENTA)	//!< \hideinitializer \brief ANSI color option: pink foreground
#define LS_ANSI_BG_PINK						__LS_ANSI_MKBCOLOR_BRIGHT(__LS_ANSI_COLOR_MAGENTA)	//!< \hideinitializer \brief ANSI color option: pink background


#define LS_ANSI_ESCAPE_START				__LS_ANSI("\x1B[")	//!< \hideinitializer \brief Starts an ANSI escape sequence.
#define LS_ANSI_ESCAPE_OPT					__LS_ANSI(";")		//!< \hideinitializer \brief Separates options.
#define LS_ANSI_ESCAPE_END					__LS_ANSI("m")		//!< \hideinitializer \brief Ends an ANSI escape sequence.


//! \hideinitializer \brief Starts an ANSI escape sequence, inserts the specified options, and ends the ANSI escape sequence.
#define LS_ANSI_WOPT(opt)					__LS_ANSI(LS_ANSI_ESCAPE_START "0" LS_ANSI_ESCAPE_OPT opt LS_ANSI_ESCAPE_END)

//! \hideinitializer \brief Wraps an ANSI escape sequence with the specified options around string \p x.
#define LS_ANSI_WRAP(x, ...)				LS_ANSI_WOPT(LS_ANSI_OPT_CONCAT(__VA_ARGS__)) x LS_ANSI_WOPT("0")




#endif
