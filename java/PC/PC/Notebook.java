package PC;

public class Notebook extends PCPortatile {
    private boolean webcam;
    private int risoluzioneWebcam;

    public Notebook(String processore, String marca, String modello, String os, int ram, int memMassa, double peso, double altezza, double larghezza, double profondita, double diagonale, boolean wireless, boolean webcam, int risoluzioneWebcam) {
        super(processore, marca, modello, os, ram, memMassa, peso, altezza, larghezza, profondita, diagonale, wireless);
        this.webcam = webcam;
        this.risoluzioneWebcam = risoluzioneWebcam;
    }
}
