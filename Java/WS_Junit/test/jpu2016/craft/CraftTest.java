package jpu2016.craft;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public abstract class CraftTest {

	protected Classe craft;

	@BeforeEach
	public abstract void setUp();

	@Test
	public void testGetHit() {
		assertNotNull(this.craft.getHit());
	}

}
