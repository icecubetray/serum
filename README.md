Serum
===

C library focused on cryptography and more.

Features
===
- Crypto
	- Padding
		- [ISO 9797-1 methods 1 and 2](https://en.wikipedia.org/wiki/ISO/IEC_9797-1#Padding)
	- Block ciphers
		- [XXTEA](https://en.wikipedia.org/wiki/XXTEA)
- Misc
	- Debugging
		- [Detailed function return values](./libserum/core/result.h)
		- [Memory dump functions](./libserum/debug/memdump.h)
	- Macros
		- [I/O pointer selection (w/ and w/out copy)](./libserum/core/ptrarithmetic.h#L40)
	- Compile-time detection of:
		- [Operating system](./libserum/core/detect_os.h)
		- [Compiler](./libserum/core/detect_compiler.h)
		- [Platform](./libserum/core/detect_platform.h)
		- [Endianness](./libserum/core/detect_endianness.h)
