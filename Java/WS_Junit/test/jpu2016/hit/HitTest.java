package jpu2016.hit;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.fail;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class HitTest {
	private Hit hit;

	@BeforeAll
	static void setUpBeforeClass() {
	}

	@AfterAll
	static void tearDownAfterClass() {
	}

	@BeforeEach
	public void setUp() {
		this.hit = new Hit(1, 10, TypeHit.NORMAL);
	}

	@AfterEach
	public void tearDown() {
	}

	@Test
	public void testGetStrength() {
		final int expected = 1;
		assertEquals(expected, this.hit.getStrength());
	}

	@Test
	public void testGetRange() {
		final int expected = 10;
		assertEquals(expected, this.hit.getRange());
	}

	@Test
	public void testGetTypeHit() {
		final TypeHit expected = TypeHit.NORMAL;
		assertEquals(expected, this.hit.getTypeHit());
	}

	@Test
	public void excepStrengthMinRange() {
		try {
			new Hit(-1, 1, TypeHit.NORMAL);
			fail("Should throw exception when Strength < 0");
		} catch (final Exception e) {
			final String expected = "Strength out of range";
			assertEquals(expected, e.getMessage());
		}
	}

	@Test
	public void excepStrengthMaxRange() {
		try {
			new Hit(101, 1, TypeHit.NORMAL);
			fail("Should throw exception when Strength > 100");
		} catch (final Exception e) {
			final String expected = "Strength out of range";
			assertEquals(expected, e.getMessage());
		}
	}

	@Test
	public void excepRangeMinRange() {
		try {
			new Hit(50, -1, TypeHit.NORMAL);
			fail("Should throw exception when Range < 0");
		} catch (final Exception e) {
			final String expected = "Range out of range";
			assertEquals(expected, e.getMessage());
		}
	}

	@Test
	public void excepRangeMaxRange() {
		try {
			new Hit(50, 11, TypeHit.NORMAL);
			fail("Should throw exception when Range > 10");
		} catch (final Exception e) {
			final String expected = "Range out of range";
			assertEquals(expected, e.getMessage());
		}
	}
}
