public class AbstractFactory {
    public static Factory getFactory(String factoryType) {
        if(factoryType == null)
            return null;
        if(factoryType.equalsIgnoreCase("SHAPE")){
            return new ShapeFactory();
        }else if(factoryType.equalsIgnoreCase("COLOR")){
            return new ColorFactory();
        }
        return null;
    }   
}
