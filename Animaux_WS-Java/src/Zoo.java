import java.util.ArrayList;
public class Zoo {
	ArrayList<Animal> animaux = new ArrayList<>();
	public void ajouterAnimal(Animal o) {
		animaux.add(o);
	}
	@Override
	public String toString() {
		String res= "Zoo : ";
		for (Animal a: animaux)
			res+=" "+a.getNom();
		return res;
	}
	
}
