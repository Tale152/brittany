/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package utility;

/**
 * Pair is an generic utility class used to contain in
 * a single object two values logically connected in some way.
 */
public class Pair<X,Y> {
	
	private final X x;
	private final Y y;	
	
	/**
	 * Constructor of Pair.
	 * 
	 * @param x the first generic value of the Pair.
	 * @param y the second generic value of the Pair.
	 */
	public Pair(final X x, final Y y) {
		this.x = x;
		this.y = y;
	}

	/**
	 * A Pair has a generic first element.
	 * 
	 * @return the first generic value of the Pair.
	 */
	public X getX() {
		return x;
	}

	/**
	 * A Pair has a generic second element.
	 * 
	 * @return the second generic value of the Pair.
	 */
	public Y getY() {
		return y;
	}

	@Override
	public String toString() {
		return "Pair [x=" + x + ", y=" + y + "]";
	}
	
}
