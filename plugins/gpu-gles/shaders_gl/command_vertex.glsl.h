#include "shaders_common.h"

#undef command_vertex_name_
#if defined(FILTER_SABR) || defined(FILTER_XBR)
#define command_vertex_name_ command_vertex_xbr
#else
#define command_vertex_name_ command_vertex
#endif

/*
  scale = 0.001;
  transformMatrix = new THREE.Matrix4()
    .makeScale(scale, -scale, 1)
    .premultiply(new THREE.Matrix4().makeTranslation(0, 1, 0))
    .toArray();
*/

static const char * command_vertex_name_ = GLSL_VERTEX "\n\
in vec4 position;\n\
in ivec4 color;\n\
in vec2 texCoord;\n\
\n\
out vec4 vColor;\n\
flat out vec4 vColorFlat;\n\
out vec2 vTexCoord;\n\
\n\
uniform mat4 uModelViewMatrix;\n\
uniform mat4 uProjectionMatrix;\n\
uniform int uVr;\n\
// uniform mat4 uTextureMatrix;\n\
// uniform sampler2D uTexture;\n\
// uniform float uAlpha;\n\
// uniform int uAlphaTest;\n\
// uniform int uAlphaFunc;\n\
// uniform int uColorEnabled;\n\
// uniform int uTextureEnabled;\n\
// uniform vec4 uColor;\n\
// uniform int uShadeModel;\n\
\n\
void main() {\n\
   vec3 p;\n\
   mat4 modelViewMatrix = uModelViewMatrix;\n\
   if (uVr == 0) {\n\
     p = position.xyz;\n\
   } else {\n\
     float q = position.w/3000.0;\n\
     p = vec3((position.x - 300.0) * q * 3.0, (position.y - 150.0) * q * 3.0 * 2.0, -q);\n\
     mat4 transformMatrix = mat4(0.001, 0, 0, 0, 0, -0.001, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1);\n\
     modelViewMatrix *= transformMatrix;\n\
   }\n\
   gl_Position = uProjectionMatrix * modelViewMatrix * vec4(p, 1.0);\n\
   vec4 fColor = vec4(float(color.r)/255.0, float(color.g)/255.0, float(color.b)/255.0, float(color.a)/255.0);\n\
   vColor = fColor;\n\
   vColorFlat = fColor;\n\
   vTexCoord = texCoord;\n\
}\n\
";

#undef command_vertex_name_
