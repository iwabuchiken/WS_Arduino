import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.Locale;
import java.util.StringTokenizer;


public class Tmp {

	int peace, love, arduino;
	
	int numOf_kw_1;
	
	String feed;
	
	String kw_1 = "economic";
	
	void fetchData() {

		  // strings for feed parce
		  String data;
		  String chunk;

//		  String kw_1 = "economic";

		  int numOf_kw_1 = 0;
		  
		  // init counters => 0
		//  peace = (int)random(255);
		//  peace = (int)random(100);
		//  peace = 50;
//		  num_kw_1 = 0;
		  peace = 0;
		  
		  love = 0;
		  
		  arduino = 0;
		  
		  ///////////////////////////////////
		  //
		  // processes
		  //
		  ///////////////////////////////////
		  try {
		    
		    URL url = new URL(feed);
		    
		    URLConnection conn = url.openConnection();
		    
		    conn.connect();
		    
		    String msg;
		    msg = String.format("[%s : %d] url => connected (%s)", Thread
		        .currentThread().getStackTrace()[1].getFileName(), Thread
		        .currentThread().getStackTrace()[1].getLineNumber(), feed);

		    System.out.println(msg);
		    
//		    String msg;
			msg = String.format(Locale.JAPAN, "[%s : %d] getting input stream...", Thread.currentThread()
					.getStackTrace()[1].getFileName(), Thread.currentThread()
					.getStackTrace()[1].getLineNumber());

			System.out.println(msg);
			
		    
		    // virtual pipe
		    BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
		    
//		    String msg;
			msg = String.format(Locale.JAPAN, "[%s : %d] input stream => obtained", Thread.currentThread()
					.getStackTrace()[1].getFileName(), Thread.currentThread()
					.getStackTrace()[1].getLineNumber());

			System.out.println(msg);
			
			while((data = in.readLine()) != null) {
				
				StringTokenizer st = new StringTokenizer(data, "\"<>,.()[] ");
				
				///////////////////////////////////
				//
				// count: words
				//
				///////////////////////////////////
				while(st.hasMoreTokens()) {
					
					chunk = st.nextToken().toLowerCase();
					
					if (chunk.lastIndexOf("love") >= 0) {

						love++;

					}//if (chunk.lastIndexOf("love") >= 0)
					
					if (chunk.lastIndexOf("peace") >= 0) {
						
						peace ++;
						
					}//if (chunk.lastIndexOf("love") >= 0)
					
					if (chunk.lastIndexOf("arduino") >= 0) {
						
						arduino ++;
						
					}//if (chunk.lastIndexOf("love") >= 0)
					
					if (chunk.lastIndexOf(kw_1) >= 0) 
						
								numOf_kw_1 ++;
						
					//if (chunk.lastIndexOf("love") >= 0)
					
				}//while(st.hasMoreTokens())
				
////				String msg;
//				msg = String.format(Locale.JAPAN, "[%s : %d] tokens => %d", Thread
//						.currentThread().getStackTrace()[1].getFileName(), Thread
//						.currentThread().getStackTrace()[1].getLineNumber(), st.countTokens());
		//
//				System.out.println(msg);
				
			}//while((data = in.readLine()) != null)
		    
			// modify numbers
			if (peace > 64) peace = 64;
			if (love > 64) love = 64;
			if (arduino > 64) arduino = 64;
			
//			String msg;
			msg = String.format(Locale.JAPAN, 
					"[%s : %d] peace = %d / love = %d / ard = %d / numOf_kw_1 = %d", 
						Thread.currentThread()
						.getStackTrace()[1].getFileName(), Thread.currentThread()
						.getStackTrace()[1].getLineNumber(), 
						peace, love, arduino, numOf_kw_1
			);

			System.out.println(msg);

			
			// finalize the numbers
			peace = peace * 4;
			love = love * 4;
			arduino = arduino * 4;
			
//		    String msg;
//		    msg = String.format("[%s : %d] executing fetch...", Thread
////		        msg = String.format(Locale.JAPAN, "[%s : %d] executing fetch...", Thread
//		        .currentThread().getStackTrace()[1].getFileName(), Thread
//		        .currentThread().getStackTrace()[1].getLineNumber());
		//
//		    System.out.println(msg);
		    
		    
		  } catch (Exception ex) {
		    
		    ex.printStackTrace();
		    
		    String msg;
		    msg = String.format("[%s : %d] ERROR: %s", Thread
//		        msg = String.format(Locale.JAPAN, "[%s : %d] ERROR: %s", Thread
		        .currentThread().getStackTrace()[1].getFileName(), Thread
		        .currentThread().getStackTrace()[1].getLineNumber(), ex.getMessage());

		    System.out.println(msg);
		    
		  }//try
		  
		}//void fetchData()

	boolean is_Numeric(String str) {
		
		boolean result = str.matches("((-|\\+)?[0-9]+(\\.[0-9]+)?)+");
		
		return result;
		
//		return false;
		
	}
	
}
