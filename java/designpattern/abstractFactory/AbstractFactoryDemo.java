public class AbstractFactoryDemo {
    public static void main(String[] args) {
        Factory shapeFactory = AbstractFactory.getFactory("shape");
        Factory colorFactory = AbstractFactory.getFactory("color");
        
        Shape square = shapeFactory.getShape("square");
        square.draw();

        Shape rectangle = shapeFactory.getShape("rectangle");
        rectangle.draw();

        Shape circle = shapeFactory.getShape("circle");
        circle.draw();

        Color red = colorFactory.getColor("red");
        red.fill();

        Color green = colorFactory.getColor("green");
        green.fill();

        Color yellow = colorFactory.getColor("yellow");
        yellow.fill();
    }
}
