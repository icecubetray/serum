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


#include "./utilities.h"




FILEID("Utilities for collections.");




void *const
ls_pcollection_find(ls_pcollection_t collection, const void *const find, const size_t size) {
#if (LS_SANITY)
	if (collection == NULL || size == 0) {
		return NULL;
	}
#endif

	size_t i;
	for (i = 0; i < size; ++i) {
		if (collection[i] == find) {
			return ((void *const)&collection[i]);
		}
	}

	return NULL;
}


void *const
ls_pcollection_rfind(ls_pcollection_t collection, const void *const find, const size_t size) {
	if (collection == NULL || size == 0) {
		return NULL;
	}

	size_t i;
	for (i = size; i--;) {
		if (collection[i] == find) {
			return ((void *const)&collection[i]);
		}
	}

	return NULL;
}
