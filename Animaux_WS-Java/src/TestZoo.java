public class TestZoo{
	public static void main (String[] args) {
		Chimpanze c1= new Chimpanze("Cheeta");
		Requins r1 = new Requins("Jaws");
		Requins r2 = new Requins("Ham");
		Tortue t1 = new Tortue("Ismaaaa");
		
		System.out.println(Animal.DESCRIPTION);
		System.out.println(c1);
		System.out.println(Chimpanze.DESCRIPTION);
		System.out.println(r1);
		System.out.println(r2);
		System.out.println(Requins.DESCRIPTION);
		System.out.println(t1);
		
		Zoo z1 = new Zoo();
		z1.ajouterAnimal(c1);
		z1.ajouterAnimal(t1);
		z1.ajouterAnimal(r1);
		z1.ajouterAnimal(r2);
		System.out.println(z1);
	}
}