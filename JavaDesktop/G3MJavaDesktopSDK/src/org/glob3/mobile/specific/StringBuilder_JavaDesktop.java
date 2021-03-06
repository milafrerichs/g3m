

package org.glob3.mobile.specific;

import org.glob3.mobile.generated.IStringBuilder;


public final class StringBuilder_JavaDesktop
         extends
            IStringBuilder {

   private final StringBuilder _builder = new StringBuilder();


   @Override
   protected IStringBuilder getNewInstance() {
      return new StringBuilder_JavaDesktop();
   }


   @Override
   public IStringBuilder addDouble(final double d) {
      _builder.append(d);
      return this;
   }


   @Override
   public IStringBuilder addString(final String s) {
      _builder.append(s);
      return this;
   }


   @Override
   public IStringBuilder addBool(final boolean b) {
      _builder.append(b);
      return this;
   }


   @Override
   public String getString() {
      return _builder.toString();
   }


   @Override
   public IStringBuilder addFloat(final float f) {
      _builder.append(f);
      return this;
   }


   @Override
   public IStringBuilder addInt(final int i) {
      _builder.append(i);
      return this;
   }


   @Override
   public IStringBuilder addLong(final long l) {
      _builder.append(l);
      return this;
   }

}
