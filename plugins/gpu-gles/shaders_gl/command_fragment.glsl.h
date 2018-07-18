#include "shaders_common.h"

#undef command_fragment_name_

#ifdef FILTER_SABR
#define command_fragment_name_ command_fragment_sabr
#elif defined(FILTER_XBR)
#define command_fragment_name_ command_fragment_xbr
#elif defined(FILTER_BILINEAR)
#define command_fragment_name_ command_fragment_bilinear
#elif defined(FILTER_3POINT)
#define command_fragment_name_ command_fragment_3point
#elif defined(FILTER_JINC2)
#define command_fragment_name_ command_fragment_jinc2
#else
#define command_fragment_name_ command_fragment
#endif

static const char * command_fragment_name_ = GLSL_FRAGMENT "\n\
in vec4 vColor;\n\
flat in vec4 vColorFlat;\n\
in vec2 vTexCoord;\n\
\n\
uniform mat4 uModelViewMatrix;\n\
uniform mat4 uProjectionMatrix;\n\
uniform mat4 uTextureMatrix;\n\
uniform sampler2D uTexture;\n\
uniform float uAlpha;\n\
uniform int uAlphaTest;\n\
uniform int uAlphaFunc;\n\
uniform int uColorEnabled;\n\
uniform int uTextureEnabled;\n\
uniform vec4 uColor;\n\
uniform int uShadeModel;\n\
out vec4 oColor;\n\
\n\
void main() {\n\
   // oColor = uColor;\n\
   // oColor = vec4(1.0, 1.0, 1.0, 1.0);\n\
   if (uColorEnabled != 0) {\n\
     if (uShadeModel == 0) {\n\
       oColor = vColorFlat;\n\
     } else {\n\
       oColor = vColor;\n\
     }\n\
   } else {\n\
     oColor = uColor;\n\
   }\n\
   if (uTextureEnabled != 0) {\n\
     // oColor += texture2D(uTexture, (uTextureMatrix * vec4(vTexCoord, 0.0, 1.0)).xy);\n\
     oColor *= texture2D(uTexture, (uTextureMatrix * vec4(vTexCoord, 0.0, 1.0)).xy);\n\
   }\n\
   if (uAlphaTest != 0) {\n\
     if (uAlphaFunc == 0) {\n\
       if (oColor.a == uAlpha) {\n\
         // nothing\n\
       } else {\n\
         discard;\n\
       }\n\
     } else if (uAlphaFunc == 1) {\n\
       if (oColor.a != uAlpha) {\n\
         // nothing\n\
       } else {\n\
         discard;\n\
       }\n\
     } else if (uAlphaFunc == 2) {\n\
       if (oColor.a > uAlpha) {\n\
         // nothing\n\
       } else {\n\
         discard;\n\
       }\n\
     } else if (uAlphaFunc == 3) {\n\
       if (oColor.a < uAlpha) {\n\
         // nothing\n\
       } else {\n\
         discard;\n\
       }\n\
     }\n\
   }\n\
}\n\
";

#undef command_fragment_name_
