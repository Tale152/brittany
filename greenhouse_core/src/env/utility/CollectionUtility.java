package utility;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class CollectionUtility {
	
	public static <K,V> Map<K,V> toMap(List<Pair<K,V>> list){
		return list.stream().collect(Collectors.toMap(p -> p.getX(), p -> p.getY()));
	}
}
