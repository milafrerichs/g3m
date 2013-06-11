package org.glob3.mobile.generated; 
////////////////////////////////////////////////////////////////////////
public class GPUUniformValueFloat extends GPUUniformValue
{
  public double _value;

  public GPUUniformValueFloat(double d)
  {
     super(GLType.glFloat());
     _value = d;
  }

  public final void setUniform(GL gl, IGLUniformID id)
  {
    gl.uniform1f(id, (float)_value);
  }
  public final boolean isEqualsTo(GPUUniformValue v)
  {
    GPUUniformValueFloat v2 = (GPUUniformValueFloat)v;
    return _value == v2._value;
  }
  public final GPUUniformValue deepCopy()
  {
    return new GPUUniformValueFloat(_value);
  }

  public final void copyFrom(GPUUniformValue v)
  {
    _value = ((GPUUniformValueFloat)v)._value;
  }

  public final String description()
  {
    IStringBuilder isb = IStringBuilder.newStringBuilder();
    isb.addString("Uniform Value Float: ");
    isb.addDouble(_value);
    String s = isb.getString();
    if (isb != null)
       isb.dispose();
    return s;
  }
}