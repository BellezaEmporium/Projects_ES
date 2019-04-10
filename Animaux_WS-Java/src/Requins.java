public class Requins extends Poisson{

	public Requins (String nom) {
		super(nom);
	}

	@Override
	public String son() {
		return "argh...";
	}
	public static String DESCRIPTION="Les requins sont des poissons fascinants. Avec leur grande mâchoire, ils dévorent tout sur leur passage.";

}