import Scuole.*;

public class Main {
    public static void main(String[] args) {
        Tecnico volterra = new Tecnico("VEIT202324", "Istituto Tecnico Tecnologico Statale Vito Volterra", "Via a studiare 69", "San Donà di Piave", 1500, 35, 0, 20);
        System.out.println(volterra.toString());
        System.out.println("soldi: " + Tools.ritornaContributo(volterra));
    }
}