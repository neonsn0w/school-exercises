package PC;

public class Desktop extends PCFisso {
    private String schedaVideo, schedaAudio;

    public Desktop(String processore, String marca, String modello, String os, int ram, int memMassa, String tipoCase, String schedaVideo, String schedaAudio) {
        super(processore, marca, modello, os, ram, memMassa, tipoCase);
        this.schedaVideo = schedaVideo;
        this.schedaAudio = schedaAudio;
    }

    public String getSchedaVideo() {
        return schedaVideo;
    }

    public String getSchedaAudio() {
        return schedaAudio;
    }
}
