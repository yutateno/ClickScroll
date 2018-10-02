#pragma once

// É}ÉNÉç
#define POINTER_RELEASE(p) {if(p!=NULL) { delete p; p=NULL; } }
#define VECTOR_RELEASE(p) { p.clear(); p.shrink_to_fit(); }
#define GRAPHIC_RELEASE(p) { if(p!=-1) { DeleteGraph(p); p=-1; } }