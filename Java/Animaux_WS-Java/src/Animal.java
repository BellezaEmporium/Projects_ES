public abstract class Animal {
	
	private String nom;
	public Animal(String name) {
		this.setNom(name);
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String toString() {
		return "Je suis " + this.nom + " et je fais " + this.son();
	}

	public static String DESCRIPTION="Un animal est un être vivant";
	
	public abstract String son();
}