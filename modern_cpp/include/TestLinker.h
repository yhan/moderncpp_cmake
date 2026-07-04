/**
 *
 * Experimented #pragma once over HEAD FILE VS CPP FILE
 * -------------------------------------------------------------
 * I try to understand the difference between including a header file and including a cpp file.
 * why pragma once does not introduce double definition of functions when including a header file in multiple translation units,
 * but it does introduce double definition of functions when including a cpp file in multiple translation units.
 *
* The difference is what is inside the file:
File               Contains                              Effect when included in N translation units
-------------------------------------------------------------------------------------------------------------------------------------
TestLinker.h       declaration only                      N copies of declaration ? fine, no code emitted
TestLinker.cpp     definition (body)                     N copies of definition ? N .obj files each with a body ? linker error
 *
 *
 */
# pragma once
int* hello();
