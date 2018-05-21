package MES;

import java.util.Vector;

public class Sorting {
	
	public Sorting() {}
	
	public void insertionSort(Vector<Order> v) {
		System.out.println(v.size());
	    for (int p = 1; p < v.size(); p++)
	    {
	    	if(p > 5) break;
	    	Order tmp = v.get(p).getCopy();
	    	int j;
	    	for (j = p; j > 0 && isBefore(tmp, v.get(j-1)); j--)
			{v.set(j, v.get(j-1));
			}
	    	v.set(j, tmp);
	    } 
	}
	
	public boolean isBefore(Order o1, Order o2) {
		if (!enough(o1) && enough(o2))
			return false;
		else if (enough(o1) && !enough(o2))
			return true;
		else {
			switch(o1.getDo()) {
			case "T":
				switch(o2.getDo()) {
				case "T":
					Transform t1 = (Transform)o1;
					Transform t2 = (Transform)o2;
					if(t1.machine().equals(t2.machine())) {
						if(t1.getDoTime() < t2.getDoTime())
							return true;
						else return false;
					}
					else if(t1.machine().equals("b"))
						return true;
					else if(t1.machine().equals("a")) {
						if(t2.machine().equals("c"))
							return true;
						else return false;
					}
					else return false;
				case "M":
					return true;
				case "U":
					return true;
				}
			case "M":
				switch(o2.getDo()) {
				case "T":
					return false;
				case "M":
					if (o1.getQuantity() < o2.getQuantity())
						return true;
					else return false;
				case "U":
					return true;
				}
			case "U":
				switch(o2.getDo()) {
				case "T":
					return false;
				case "M":
					return false;
				case "U":
					if (o1.getQuantity() < o2.getQuantity())
						return true;
					else return false;
				}
			}
		}
		return false;
	}

	public boolean enough(Order o) {
		switch(o.getDo()) {
		case "T":
			Transform t = (Transform)o;
			if (t.getQuantity() <= Main.stock.getQuantity(t.getFrom()))
				return true;
			else return false;
		case "M":
			Mount m = (Mount)o;
			if (m.getQuantity() <= Main.stock.getQuantity(m.getTop()) && m.getQuantity() <= Main.stock.getQuantity(m.getBottom()))
				return true;
			else return false;
		case "U":
			Unload u = (Unload)o;
			if (u.getQuantity() <= Main.stock.getQuantity(u.getType()))
				return true;
			else return false;
		default: return false;
		}
	}
	
	public boolean hasPieces(Order o) {
		switch(o.getDo()) {
		case "T":
			Transform t = (Transform)o;
			if (Main.stock.getQuantity(t.getFrom()) > 0)
				return true;
			else return false;
		case "M":
			Mount m = (Mount)o;
			if (Main.stock.getQuantity(m.getTop()) > 0 && Main.stock.getQuantity(m.getBottom()) > 0)
				return true;
			else return false;
		case "U":
			Unload u = (Unload)o;
			if (Main.stock.getQuantity(u.getType()) > 0)
				return true;
			else return false;
		default: return false;
		}
	}
}
