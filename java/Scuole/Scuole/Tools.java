package Scuole;

public class Tools {
    public static int ritornaContributo(Scuola sc) {
        int euroStudente = 0, euroClassi = 0, euroLaboratori = 0, euroSediAggiuntive = 0;
        String s = sc.getClass().getName();
        switch (s) {
            case "Scuole.Elementare":
                euroStudente = 125;
                euroSediAggiuntive = 1100;
                break;

            case "Scuole.Media":
                euroStudente = 150;
                euroLaboratori = 1100;
                euroSediAggiuntive = 9000;
                break;

            case "Scuole.Liceo":
                euroStudente = 150;
                euroLaboratori = 1100;
                break;

            case "Scuole.Tecnico":
                euroClassi = 3500;
                euroLaboratori = 6000;
                break;

            case "Scuole.Professionale":
                euroClassi = 2400;
                euroLaboratori = 3000;
                break;

            default:
                return -1;
        }


        return (sc.getnStudenti() * euroStudente) + (sc.getnClassi() * euroClassi) + (sc.getnLaboratori() * euroLaboratori) + (sc.getnSediAggiuntive() * euroSediAggiuntive);
    }
}
