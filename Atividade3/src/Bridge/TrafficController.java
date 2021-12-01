package Bridge;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class TrafficController {
	
	final Lock trava = new ReentrantLock();
	
	
	public void enterLeft() {trava.lock();}
    public void enterRight() {trava.lock();}
    public void leaveLeft() {trava.unlock();}
    public void leaveRight() {trava.unlock();}

}
