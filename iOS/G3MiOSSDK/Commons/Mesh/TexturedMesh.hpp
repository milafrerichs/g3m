//
//  TexturedMesh.hpp
//  G3MiOSSDK
//
//  Created by José Miguel S N on 12/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef G3MiOSSDK_TexturedMesh_hpp
#define G3MiOSSDK_TexturedMesh_hpp

#include "Mesh.hpp"
#include "TextureMapping.hpp"
#include "Vector3D.hpp"

#include "GLClient.hpp"


class TexturedMesh: public Mesh
{
private:
  const Mesh*           _mesh;
  const TextureMapping* _textureMapping;
  const bool            _ownedMesh;
  const bool            _ownedTexMapping;
  const bool            _transparent;

  
public:
  
  TexturedMesh(const Mesh* mesh,
               bool ownedMesh,
               TextureMapping* const textureMapping,
               bool ownedTexMapping,
               bool transparent) :
  _mesh(mesh),
  _ownedMesh(ownedMesh),
  _textureMapping(textureMapping),
  _ownedTexMapping(ownedTexMapping),
  _transparent(transparent)
  {
  }
  
  ~TexturedMesh(){
    if (_ownedMesh) {
      delete _mesh;
    } 
    if (_ownedTexMapping){
      delete _textureMapping;
    }
  }
  
  void render(const G3MRenderContext* rc,
              const GLState& parentState, const GPUProgramState* parentProgramState) const;

  Extent* getExtent()  const {
    return (_mesh == NULL) ? NULL : _mesh->getExtent();
  }
  
  int getVertexCount() const {
    return _mesh->getVertexCount();
  }
  
  const Vector3D getVertex(int i) const {
    return _mesh->getVertex(i);
  }
  
  const TextureMapping* const getTextureMapping() const {
    return _textureMapping;
  }

  bool isTransparent(const G3MRenderContext* rc) const {
    return _transparent;
  }
  
  void notifyGLClientChildrenParentHasChanged();
  void modifyGLState(GLState& glState) const;
  void modifyGPUProgramState(GPUProgramState& progState) const;
};

#endif
