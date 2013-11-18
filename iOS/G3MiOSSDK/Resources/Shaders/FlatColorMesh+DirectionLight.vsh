//
//  Default.vsh
//
//  Created by José Miguel Santana Núñez
//

attribute vec4 aPosition;
attribute vec3 aNormal;

uniform mat4 uModelview;
uniform mat4 uModel;

uniform float uPointSize;

uniform float uAmbientLight;
uniform vec4 uLightColor;

uniform vec3 uLightDirection; //We must normalize
varying vec4 lightColor;

void main() {

  vec3 normalInModel = normalize( vec3(uModel * vec4(aNormal, 0.0) ));
  vec3 lightDirNormalized = normalize( uLightDirection );
  
  float diffuseLightIntensity = max(dot(normalInModel, lightDirNormalized), 0.0);

  gl_Position = uModelview * aPosition;

  gl_PointSize = uPointSize;

  //Computing Total Light in Vertex
  lightColor = vec4(uAmbientLight, uAmbientLight, uAmbientLight, 1.0) + uLightColor * diffuseLightIntensity;
}
