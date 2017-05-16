public class ColorFactory implements Factory {
    public Color getColor(String colorType){
        if(colorType == null)
            return null;
        if(colorType.equalsIgnoreCase("RED")){
            return new Red();
        }else if(colorType.equalsIgnoreCase("GREEN")){
            return new Green();
        }else if(colorType.equalsIgnoreCase("YELLOW")){
            return new Yellow();
        }
        return null;
    }
    public Shape getShape(String shapeType){
        return null;
    }
}