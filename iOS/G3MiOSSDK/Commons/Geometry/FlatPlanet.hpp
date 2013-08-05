//
//  FlatPlanet.hpp
//  G3MiOSSDK
//
//  Created by Agustín Trujillo on 10/07/13.
//
//

#ifndef G3MiOSSDK_FlatPlanet_hpp
#define G3MiOSSDK_FlatPlanet_hpp

#include "MutableVector3D.hpp"
#include "Geodetic3D.hpp"
#include "Planet.hpp"
#include "Vector2D.hpp"


class FlatPlanet: public Planet {
private:
  const Vector2D _size;

  mutable MutableVector3D _origin;
  mutable MutableVector3D _initialPoint;
  mutable MutableVector3D _lastFinalPoint;
  mutable bool            _validSingleDrag;
  mutable MutableVector3D _lastDirection;
  
  mutable MutableVector3D _centerRay;
  mutable MutableVector3D _initialPoint0;
  mutable MutableVector3D _initialPoint1;
  mutable double          _distanceBetweenInitialPoints;
  mutable MutableVector3D _centerPoint;
  mutable double          _angleBetweenInitialRays;
  

  
public:
  
  FlatPlanet(const Vector2D& size);
  
  ~FlatPlanet() {
    
  }
  
  Vector3D getRadii() const{
    return Vector3D(_size._x, _size._y, 0);
  }
  
  Vector3D centricSurfaceNormal(const Vector3D& position) const {
    return Vector3D(0, 0, 1);
  }
  
  Vector3D geodeticSurfaceNormal(const Vector3D& position) const {
    return Vector3D(0, 0, 1);
  }
  
  Vector3D geodeticSurfaceNormal(const MutableVector3D& position) const {
    return Vector3D(0, 0, 1);
  }
  
  
  Vector3D geodeticSurfaceNormal(const Angle& latitude,
                                 const Angle& longitude) const;
  
  Vector3D geodeticSurfaceNormal(const Geodetic3D& geodetic) const {
    return Vector3D(0, 0, 1);
  }
  
  Vector3D geodeticSurfaceNormal(const Geodetic2D& geodetic) const {
    return Vector3D(0, 0, 1);
  }
  
  std::vector<double> intersectionsDistances(const Vector3D& origin,
                                             const Vector3D& direction) const;
  
  Vector3D toCartesian(const Angle& latitude,
                       const Angle& longitude,
                       const double height) const;
  
  Vector3D toCartesian(const Geodetic3D& geodetic) const {
    const double x = geodetic.longitude().degrees() * _size._x / 360.0;
    const double y = geodetic.latitude().degrees() * _size._y / 180.0;
    return Vector3D(x, y, geodetic.height());
  }
  
    
  Vector3D toCartesian(const Geodetic2D& geodetic) const {
    return toCartesian(geodetic.latitude(),
                       geodetic.longitude(),
                       0.0);
  }
  
  Vector3D toCartesian(const Geodetic2D& geodetic,
                       const double height) const {
    return toCartesian(geodetic.latitude(),
                       geodetic.longitude(),
                       height);
  }
  
  Geodetic2D toGeodetic2D(const Vector3D& position) const;
  
  Geodetic3D toGeodetic3D(const Vector3D& position) const;
  
  Vector3D scaleToGeodeticSurface(const Vector3D& position) const;
  
  Vector3D scaleToGeocentricSurface(const Vector3D& position) const;
  
  std::list<Vector3D> computeCurve(const Vector3D& start,
                                   const Vector3D& stop,
                                   double granularity) const;
  
  Geodetic2D getMidPoint (const Geodetic2D& P0, const Geodetic2D& P1) const;
  
  
  double computePreciseLatLonDistance(const Geodetic2D& g1,
                                      const Geodetic2D& g2) const;
  
  double computeFastLatLonDistance(const Geodetic2D& g1,
                                   const Geodetic2D& g2) const;
  
  Vector3D closestPointToSphere(const Vector3D& pos, const Vector3D& ray) const;
  
  Vector3D closestIntersection(const Vector3D& pos, const Vector3D& ray) const;
  
  
  MutableMatrix44D createGeodeticTransformMatrix(const Geodetic3D& position) const;
  
  bool isFlat() const { return true; }
  
  void beginSingleDrag(const Vector3D& origin, const Vector3D& initialRay) const;
  
  MutableMatrix44D singleDrag(const Vector3D& finalRay) const;
  
  Effect* createEffectFromLastSingleDrag() const;
  
  void beginDoubleDrag(const Vector3D& origin,
                       const Vector3D& centerRay,
                       const Vector3D& initialRay0,
                       const Vector3D& initialRay1) const;
  
  MutableMatrix44D doubleDrag(const Vector3D& finalRay0,
                              const Vector3D& finalRay1) const;
  
  Effect* createDoubleTapEffect(const Vector3D& origin,
                                const Vector3D& centerRay,
                                const Vector3D& tapRay) const;


};


#endif