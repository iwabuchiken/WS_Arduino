##ruby C:\WORKS\WS\WS_Arduino\D.1-49\D-12_irremote\D_12_irremote_s_1\util.rb
def execute

#  a_hot = "2433925,52,36,50,36,50,36,50,36,50,36,50,2524,356,163,51,122,50,36,50,36,50,36,50,122,50,36,52,34,50,36,50,36,234,416,440,469,338,440,396,469,357,421,410,416,436,396,415,437,394,3223,354,164,50,122,50,36,50,36,50,36,226,466,333,533,298,416,461,381,404,416,442,390,415,441,399,407,415,3173,354,163,50,122,50,36,50,36,50,36,242,450,381,484,397,468,312,416,446,386,415,446,398,404,459,382,404,460,396,391,415,439,397,411,456,379,411,416,436,396,414,435,396,416,450,381,415"
  

  a_hot_1 = "746389,53,36,47,39,47,38,50,36,50,36,52,2522,354,166,44,128,48,36,50,41,44,39,50,123,50,38,44,42,44,41,47,39,121,484,347,433,399,416,444,388,415,448,384,416,456,471,320,416,415,3330,351,172,47,125,47,38,45,38,50,36,84,351,391,401,415,436,396,416,446,388,413,452,393,403,415,429,402,3385,352,168,50,123,50,36,47,38,47,39,50,298,408,416,436,470,340,440,391,416,415,421,410,452,391,405,462,469,316,416,439,392,415,446,393,472,390,388,406,416,436,396,415,440,393,471,394,385,410"
  b_hot_1 = a_hot_1.split(",")
  
  a_hot_2 = "210034,55,33,51,36,47,39,52,33,50,36,50,2524,354,166,50,123,47,39,47,39,46,39,50,122,50,36,48,39,52,33,50,36,123,483,348,430,401,416,446,385,415,446,386,416,456,472,318,416,415,3330,352,168,50,122,50,36,50,36,50,36,83,312,433,398,416,435,396,416,446,386,415,449,393,405,415,430,402,3385,357,163,47,126,50,36,50,36,50,36,50,295,410,416,437,470,340,438,393,416,416,418,413,452,396,399,465,471,310,416,442,388,415,446,396,470,393,387,402,416,436,395,415,438,395,472,393,386,410"
  b_hot_2 = a_hot_2.split(",")
  
  a_hot_3 = "161776,52,36,53,33,48,38,53,32,50,36,50,2524,354,166,50,122,50,36,50,36,50,36,48,122,53,36,50,36,50,36,50,36,125,481,350,430,402,416,443,388,415,444,387,416,460,467,319,416,415,3329,356,164,50,122,50,36,50,36,53,32,85,348,396,399,415,434,399,414,445,386,415,448,393,406,415,428,403,3384,352,168,47,126,50,36,50,36,50,36,50,295,411,416,433,472,342,437,395,415,415,417,414,451,393,403,461,471,314,416,444,387,415,447,391,472,396,384,404,416,438,394,415,439,392,472,394,385,411"
  b_hot_3 = a_hot_3.split(",")
  
  a_stop = "549961,52,36,50,36,50,36,50,36,50,36,50,2526,352,166,53,119,51,36,50,36,50,36,50,122,53,32,51,36,50,36,50,36,126,481,350,428,403,416,442,390,415,442,389,416,457,469,321,416,415,3328,354,166,53,120,50,36,52,32,53,33,86,312,431,400,415,434,399,415,449,382,416,446,399,402,415,427,404,3383,357,163,53,120,53,32,53,32,53,33,53,292,412,416,437,467,342,435,399,413,415,416,415,450,399,399,465,466,314,416,446,386,415,443,399,466,399,378,408,416,440,392,415,438,399,466,398,380,412"  
  b_stop = a_stop.split(",")
    
  a_stop_1 = "236424,55,33,53,32,56,27,56,32,53,32,54,2524,354,163,53,120,52,32,56,28,56,33,56,117,54,32,53,33,53,32,53,32,126,481,350,429,402,416,445,386,415,441,390,416,460,467,320,416,415,3332,354,163,56,117,55,28,55,32,54,33,85,312,434,397,415,434,399,414,450,381,415,447,400,401,415,428,404,3384,357,163,53,120,53,33,53,33,53,32,54,292,411,416,438,466,342,434,404,410,452,379,415,416,433,398,466,380,401,416,446,385,415,443,399,405,460,466,320,416,440,391,415,438,399,466,399,380,411"  
  b_stop_1 = a_stop_1.split(",")
    
  a_stop_2 = "83600,58,28,55,32,56,27,56,32,56,27,56,2522,356,163,53,120,53,33,53,33,56,27,56,120,53,33,53,33,53,32,53,32,53,380,316,464,400,379,415,536,316,396,467,467,314,463,367,416,415,3544,357,161,55,117,52,33,53,32,56,28,58,129,415,526,313,467,399,379,410,454,399,394,415,434,399,415,450,3562,359,161,56,117,53,33,53,32,56,28,55,120,399,388,415,529,313,405,459,378,409,416,440,392,415,437,399,411,454,378,414,416,433,398,470,463,316,415,447,384,415,445,399,404,462,379,406,460,372"  
  b_stop_2 = a_stop_2.split(",")
    
  a_stop_3 = "177154,55,32,53,32,54,33,56,28,56,32,56,2520,356,163,53,120,56,28,55,32,54,32,56,118,52,33,53,32,53,33,53,33,125,481,349,430,401,416,444,387,415,444,387,416,461,466,319,416,416,3332,356,161,52,120,56,28,55,34,52,33,84,312,436,396,415,436,401,410,451,380,415,448,399,400,415,427,404,3386,359,161,56,116,56,29,55,32,53,33,53,290,412,416,439,466,341,437,399,411,456,376,414,416,437,394,470,377,400,416,447,384,415,444,399,404,461,466,319,416,441,390,415,440,398,466,399,380,410"  
  b_stop_3 = a_stop_3.split(",")
    
  print "b_hot => ", b_hot_1.length
  print "\n"
#  print "b_hot => ", b_hot.length
  print "b_stop => ", b_stop.length
  print "\n"
  
  #########################
  # hots, stops: first 6 numbers
  #########################
  hot13_1 = b_hot_1[0..13].join(",")
  
  print "hot13_1 => ", hot13_1, "\n"
  
  hot13_2 = b_hot_2[0..13].join(",")
  
  print "hot13_2 => ", hot13_2, "\n"
  
  hot13_3 = b_hot_3[0..13].join(",")
  
  print "hot13_3 => ", hot13_3, "\n"

  # stops
  stop13_1 = b_stop_1[0..13].join(",")
  
  print "stop13_1 => ", stop13_1, "\n"
  
  stop13_2 = b_stop_2[0..13].join(",")
  
  print "stop13_2 => ", stop13_2, "\n"
  
  stop13_3 = b_stop_3[0..13].join(",")
  
  print "stop13_3 => ", stop13_3, "\n"
    
  #########################
  # hots, stops: 13 ~ 30
  #########################
  hot13_30_1 = b_hot_1[13..30].join(",")
  
  print "hot13_30_1 => ", hot13_30_1, "\n"
  
  hot13_30_2 = b_hot_2[13..30].join(",")
  
  print "hot13_30_2 => ", hot13_30_2, "\n"
  
  hot13_30_3 = b_hot_3[13..30].join(",")
  
  print "hot13_30_3 => ", hot13_30_3, "\n"

  # stops
  stop13_30_1 = b_stop_1[13..30].join(",")
  
  print "stop13_30_1 => ", stop13_30_1, "\n"
  
  stop13_30_2 = b_stop_2[13..30].join(",")
  
  print "stop13_30_2 => ", stop13_30_2, "\n"
  
  stop13_30_3 = b_stop_3[13..30].join(",")
  
  print "stop13_30_3 => ", stop13_30_3, "\n"
    
  #########################
  # hots, stops: 50 ~ 64
  #########################
  puts
  puts
  
  hot50_64_1 = b_hot_1[50..64].join(",")
  
  print "hot50_64_1 => ", hot50_64_1, "\n"
  
  hot50_64_2 = b_hot_2[50..64].join(",")
  
  print "hot50_64_2 => ", hot50_64_2, "\n"
  
  hot50_64_3 = b_hot_3[50..64].join(",")
  
  print "hot50_64_3 => ", hot50_64_3, "\n"

  # stops
  stop50_64_1 = b_stop_1[50..64].join(",")
  
  print "stop50_64_1 => ", stop50_64_1, "\n"
  
  stop50_64_2 = b_stop_2[50..64].join(",")
  
  print "stop50_64_2 => ", stop50_64_2, "\n"
  
  stop50_64_3 = b_stop_3[50..64].join(",")
  
  print "stop50_64_3 => ", stop50_64_3, "\n"
    
  #########################
  # detect: more than 2000
  #########################
  puts
  
  puts "*********** b_hot_1 ***********"
  
  b_hot_1.each_with_index do |e, i|
    
    if e.to_i > 2000
      
      print "#{e}(#{i}), "
      
    end
    
#    print "\n"
    
  end
  
  puts
  puts "*********** b_hot_2 ***********"
  
  b_hot_2.each_with_index do |e, i|
    
    if e.to_i > 2000
      
      print "#{e}(#{i}), "
      
    end
    
#    print "\n"
    
  end
  
  puts
  puts "*********** b_hot_3 ***********"
  
  b_hot_3.each_with_index do |e, i|
    
    if e.to_i > 2000
      
      print "#{e}(#{i}), "
      
    end
    
#    print "\n"
    
  end

  puts
  
  puts
  puts "*********** b_stop_1 ***********"
  
  b_stop_1.each_with_index do |e, i|
    
    if e.to_i > 2000
      
      print "#{e}(#{i}), "
      
    end
    
#    print "\n"
    
  end

  puts
  
  puts
  puts "*********** b_stop_2 ***********"
  
  b_stop_2.each_with_index do |e, i|
    
    if e.to_i > 2000
      
      print "#{e}(#{i}), "
      
    end
    
#    print "\n"
    
  end

  puts
  
    
end

def execute_2

#  a_hot = "2433925,52,36,50,36,50,36,50,36,50,36,50,2524,356,163,51,122,50,36,50,36,50,36,50,122,50,36,52,34,50,36,50,36,234,416,440,469,338,440,396,469,357,421,410,416,436,396,415,437,394,3223,354,164,50,122,50,36,50,36,50,36,226,466,333,533,298,416,461,381,404,416,442,390,415,441,399,407,415,3173,354,163,50,122,50,36,50,36,50,36,242,450,381,484,397,468,312,416,446,386,415,446,398,404,459,382,404,460,396,391,415,439,397,411,456,379,411,416,436,396,414,435,396,416,450,381,415"
  

  a_hot_1 = "447292,55,33,53,33,53,33,53,32,53,33,50,2524,354,166,50,123,50,36,52,33,53,32,53,120,53,32,53,32,53,33,53,33,53,120,50,36,52,120,53,120,53,33,53,120,53,120,53,120,52,120,52,120,50,36,52,33,53,120,52,35,52,33,53,32,53,33,53,33,53,33,53,33,53,32,53,33,53,33,53,120,50,36,53,119,53,33,53,33,53,32,53,120,53,120,52,33,53,33,53,33,53,33,53,120,53,32,53,120,51,35,52,33,53,32,53,32,53,33,53,32,53,33,53,120,53,33,53,120,52,121,52,120,50,36,52,33,53,120,50,123,52,34,52,3475,354,166,50,122,52,35,52,33,53,32,53,120,53,33,53,32,54,32,53,33,53,120,50,36,52,120,52,121,53,34,52,120,50,123,50,122,50,123,52,120,50,36,52,33,53,120,50,36,52,33,53,33,53,33,53,33,53,33,53,33,53,33,53,32,53,33,54,32,53,120,52,33,53,33,53,32,53,32,53,120,53,33,53,32,54,32,53,33,53,32,53,33,53,32,53,33,53,32,53,32,53,33,53,32,53,33,54,32,53,33,53,32,53,33,53,33,53,33,53,120,53,32,53,120,54,32,53,120,53,33,53,3475,354,165,50,123,52,34,53,33,53,33,53,120,50,36,52,33,53,33,53,32,53,120,50,36,52,120,52,122,52,34,52,120,53,120,53,120,50,123,52,120,50,36,53,32,53,120,50,36,52,32,53,33,53,32,54,32,53,33,53,32,53,33,53,32,53,33,54,32,53,32,53,33,52,33,53,33,53,32,53,33,53,33,52,120,53,33,53,32,53,120,53,32,53,33,53,120,52,33,53,32,53,33,53,33,54,119,53,32,54,120,52,33,53,32,53,33,53,33,53,33,53,32,54,33,52,32,53,33,53,32,53,33,53,32,54,32,53,33,53,32,53,120,54,33,52,120,53,32,53,33,53,33,53,33,53,32,53,33,53,33,53,32,54,32,53,34,52,32,54,32,53,33,53,32,53,33,53,32,53,33,53,120,54,119,53,33,53,33,53,33,53,32,53,33,53,33,53,33,53,33,54,32,54,32,53,120,53,120,53,33,53,33,53,32,54,32,53,33,53,32,54,32,53,33,52,33,53,120,53,33,53,32,53,33,53,32,54,32,53,33,53,32,53,33,52,33,53,32,53,32,53,33,53,32,53,120,53,120,53,32,53,32,53,33,53,33,53,33,53,32,53,33,53,120,52,33,53,32,53,34,52,32,53,33,53,33,53,33,53,33,53,33,53,120,53,32,53,120,52,33,53,32,53,120,52,120,52"
  b_hot_1 = a_hot_1.split(",")
  
  a_hot_2 = "96656,55,33,53,32,53,33,53,32,53,33,50,2524,357,163,53,120,53,33,53,33,53,33,53,120,53,32,53,32,53,33,50,36,53,120,50,36,53,120,50,123,52,33,53,120,52,120,53,120,53,120,53,120,53,34,52,33,51,122,53,33,50,36,52,33,53,33,50,36,50,36,53,33,53,32,54,32,51,36,50,123,50,35,53,120,50,36,53,32,53,33,53,120,53,120,50,36,52,33,53,33,53,33,53,120,50,35,51,122,53,33,53,32,54,32,53,33,53,32,51,36,53,33,53,120,53,33,50,122,53,120,53,120,50,36,52,33,54,120,53,120,53,33,53,3476,356,163,50,122,52,35,52,33,53,32,53,120,53,33,53,32,53,33,50,36,50,123,53,32,53,120,50,123,50,36,52,120,53,120,53,120,50,122,53,120,50,36,52,32,53,120,52,33,52,33,53,33,50,36,52,33,53,32,53,33,53,32,53,32,51,36,54,32,52,120,51,36,52,32,53,33,51,36,52,120,53,33,53,32,53,33,53,34,52,33,53,32,53,33,53,32,54,32,53,33,53,32,53,33,53,32,53,33,51,36,52,33,52,33,53,33,52,33,53,120,53,32,53,120,53,33,53,120,53,32,53,3475,356,163,53,121,52,33,50,36,53,33,52,120,53,33,53,32,53,32,51,36,52,120,52,33,53,120,53,120,53,34,52,120,52,120,52,120,53,120,53,120,53,33,53,33,53,120,53,33,53,33,53,32,51,36,52,33,53,32,53,33,53,32,50,36,52,33,54,32,50,36,53,33,53,32,50,36,53,33,53,33,53,33,53,120,53,33,54,32,50,122,52,33,53,32,51,122,53,33,50,36,53,32,53,33,54,120,50,36,53,120,53,33,53,33,50,36,53,32,53,33,53,33,53,32,54,32,53,33,53,33,52,34,52,32,53,33,53,33,52,33,54,120,53,32,53,120,50,36,53,33,53,32,50,36,53,34,52,33,53,33,53,32,54,32,53,33,52,33,53,33,50,36,53,33,53,32,53,33,53,33,50,122,54,119,53,33,53,32,53,33,53,33,53,33,50,36,53,32,54,32,53,33,54,32,53,120,53,120,53,33,53,32,53,33,53,33,52,33,53,33,54,32,53,33,53,32,53,120,53,33,53,33,53,32,53,33,53,33,53,32,54,32,53,34,52,32,54,32,53,33,53,32,53,33,53,120,53,120,54,32,53,34,52,33,53,33,53,32,53,33,53,33,53,120,53,32,54,32,54,33,52,34,52,33,53,33,53,32,53,33,53,33,53,120,53,33,52,121,52,32,54,32,53,120,54,120,53"
  b_hot_2 = a_hot_2.split(",")
  
  a_hot_3 = "115378,52,36,53,32,50,36,50,36,50,36,50,2524,354,165,53,120,50,36,52,32,51,36,52,120,52,34,50,36,50,36,50,36,50,123,50,36,50,122,52,120,51,35,50,123,53,120,53,120,53,120,51,121,50,36,52,32,51,123,50,36,50,35,53,32,50,36,50,36,52,32,51,36,52,33,53,32,53,33,54,119,53,32,53,120,50,36,50,36,53,33,50,122,53,120,50,36,50,36,52,33,53,32,50,123,52,33,50,123,52,33,53,33,51,36,52,32,51,36,53,32,53,32,51,123,50,36,53,119,53,120,53,120,53,33,52,33,53,120,53,120,53,34,50,3480,354,163,50,122,53,33,53,32,50,36,50,122,53,33,50,36,53,33,50,36,53,120,53,33,53,120,53,120,53,33,50,122,50,123,52,120,50,122,53,120,50,36,52,33,51,122,52,33,50,36,50,36,53,33,53,32,53,33,53,32,53,33,53,33,53,32,50,36,50,122,50,35,53,32,53,33,53,32,53,120,51,35,53,33,53,32,53,33,52,32,53,33,50,36,50,36,53,33,50,36,53,33,53,33,50,36,50,36,53,34,52,33,53,32,53,33,53,32,51,123,52,33,53,120,50,36,53,120,53,32,51,3477,354,166,50,123,52,35,50,36,50,36,52,120,50,36,50,36,50,36,52,33,50,123,50,35,50,122,50,122,53,33,51,122,53,120,50,122,53,120,52,122,52,34,50,36,50,122,53,33,50,36,53,33,50,36,50,36,50,36,50,36,53,32,50,36,50,36,54,32,50,36,52,32,53,32,53,33,53,33,50,36,53,33,53,120,50,36,50,36,52,120,50,36,53,32,53,119,50,36,50,36,53,32,50,36,50,122,50,36,53,120,53,33,50,36,50,36,50,36,52,33,51,36,54,32,50,36,50,36,50,36,52,33,50,36,50,36,50,36,50,36,50,122,53,32,51,122,53,32,50,36,53,33,50,36,52,32,51,36,50,36,52,33,54,32,51,36,50,35,53,33,50,36,53,33,50,36,50,35,53,32,53,120,50,123,53,32,51,36,52,33,53,32,53,33,52,33,53,33,53,32,54,32,51,36,52,120,52,120,50,36,53,33,51,36,52,32,53,33,53,33,53,32,53,33,50,35,53,120,53,33,51,36,50,36,50,36,53,32,53,33,53,32,53,34,50,35,53,33,53,33,53,33,53,33,50,122,53,120,50,36,53,33,52,33,50,36,52,33,53,33,53,32,50,123,52,33,53,32,54,34,52,32,53,33,53,32,51,36,52,33,53,32,53,120,50,36,50,122,53,33,53,33,53,120,53,120,53"
  b_hot_3 = a_hot_3.split(",")

  hot_1 = "342,163,47,120,50,33,48,40,44,40,36,48,36,45,46,40,44,39,46,40,41,40,44,35,40,45,40,127,38,48,46,39,44,34,46,39,44,40,44,40,44,40,36,48,46,40,41,40,44,39,44,39,44,39,36,47,45,39,47,34,39,48,44,120,48,39,47,119,46,121,47,122,46,122,45,120,47,121,47,40,46,118,48,120,48,122,36,129,48,120,39,129,49,118,39,130,46,121,49,40,41,40,35,47,45,39,36,47,44,40,46,40,43,35,46,40,44,37,49,119,49,119,47,35,50,36,45,121,38,131,44,121,38,130,46,37,38,48,46,118,47,121,49,40,43,38,46,34,39,129,47,39,44,40,36,130,47,39,44,39,44,122,38,129,49,35,38,129,39,131,36,48,43,121,49,118,47,40,46,118,39,130,48,35,41,45,44,123,44,40,43,40,36,48,44,40,36,45,38,129,38,130,46,40,44,122,44,122,47,122,37,48,36,48,44,35,50,119,38,48,44,121,47,123,47,37,44,123,44,120,48,120,47,35,40,129,46,36,48,40,44,121,47,40,38,44,37,47,44,42,33,45,38,48,44,39,36,48,36,129,50,118,38,129,39,129,41,126,47,121,39,131,36,129,47,36,50,34,39,48,36,48,46,34,38,48,36,48,44,38,37,129,39,129,41,126,49,119,46,121,50,118,46,121,47,121,38,48,36,48,46,40,36,45,36,47,38,48,33,48,36,48,44,122,37,129,38,130,46,123,37,129,39,130,41,127,41,127,38,48,35,48,44,40,36,47,44,39,36,48,38,48,36,45,35,129,39,131,36,130,38,129,39,131,37,129,39,129,39,131,36,46,38,48,35,48,36,48,36,45,38,45,38,48,36,48,36,129,49,118,47,121,47,120,38,129,50,118,39,130,46,120,47,121,49,118,38,48,35,48,35,129,38,48,35,47,44,36,47,40,43,40,44,121,38,129,39,45,49,119,38,128,47,121,38,130,38,48,35,47,36,48,35,129,47,40,36,129,47,121,38,49,38,126,47,121,38,129,38,49,38,126,38,49,35,49,35,47,44,35,40,48,44,40,36,48,36,45,38,48,36,45,38,129,41,127,41,126,39,129,38,130,40,127,38,130,38,129,39,48,35,48,35,48,38,45,36,47,36,48,36,48,38,48,33,129,39,129,42,126,41,126,38,130,41,127,38,130,38,129,41"  
    
  print "b_hot => ", b_hot_1.length
  print "\n"

  puts  
  print "hot_1 => ", hot_1.split(",").length
  print "\n"
  
  #########################
  # detect: more than 2000
  #########################
  puts
  
  puts "*********** b_hot_1 ***********"
  
  b_hot_1.each_with_index do |e, i|
    
    if e.to_i > 2000
      
      print "#{e}(#{i}), "
      
    end
    
#    print "\n"
    
  end
  
  puts
  puts "*********** b_hot_2 ***********"
  
  b_hot_2.each_with_index do |e, i|
    
    if e.to_i > 2000
      
      print "#{e}(#{i}), "
      
    end
    
#    print "\n"
    
  end
    
end

def execute_3

#  a_battery = "2433925,52,36,50,36,50,36,50,36,50,36,50,2524,356,163,51,122,50,36,50,36,50,36,50,122,50,36,52,34,50,36,50,36,234,416,440,469,338,440,396,469,357,421,410,416,436,396,415,437,394,3223,354,164,50,122,50,36,50,36,50,36,226,466,333,533,298,416,461,381,404,416,442,390,415,441,399,407,415,3173,354,163,50,122,50,36,50,36,50,36,242,450,381,484,397,468,312,416,446,386,415,446,398,404,459,382,404,460,396,391,415,439,397,411,456,379,411,416,436,396,414,435,396,416,450,381,415"
  
  #########################
  # battery: 1
  #########################
  puts "************* battery: 1 *************"
  
  a_battery_1 = "164456,918,439,62,164,65,162,65,51,65,162,65,51,65,51,65,162,68,48,65,51,65,50,68,48,68,159,65,51,65,50,65,51,65,161,68,159,64,51,65,162,65,162,68,159,65,161,65,50,65,50,68,48,68,158,65,51,65,50,65,50,66,50,65,162,65,162,65,4141,918,217,62"
  b_battery_1 = a_battery_1.split(",")
  
  print "b_battery => ", b_battery_1.length
  print "\n"

  puts
  
  #########################
  # battery: 2
  #########################
  puts "************* battery: 2 *************"
  
  a_battery_2 = "69912,912,442,62,164,65,161,65,51,65,162,65,51,65,50,65,161,66,50,65,51,65,50,65,51,65,161,68,48,66,50,67,48,65,162,68,159,65,50,68,159,67,159,65,162,68,160,65,50,68,48,68,48,68,159,68,48,66,51,67,48,68,48,68,159,68,159,68,4138,917,217,62"
  b_battery_2 = a_battery_2.split(",")
  
  print "b_battery => ", b_battery_2.length
  print "\n"

  puts
  
end#def execute_3

def execute_s5_1

  #########################
  # battery: 1
  #########################
  puts "************* battery: 1 *************"
  
  a_battery_1 = "393972 HIGH,916 LOW,439 HIGH,65 LOW,161 HIGH,68 LOW,159 HIGH,68 LOW,48 HIGH,68 LOW,159 HIGH,68 LOW,48 HIGH,68 LOW,48 HIGH,68 LOW,160 HIGH,67 LOW,48 HIGH,68 LOW,48 HIGH,68 LOW,48 HIGH,77 LOW,266 HIGH,67 LOW,57 HIGH,173 LOW,98 HIGH,135 LOW,271 HIGH,65 LOW,71 HIGH,135 LOW,136 HIGH,152 LOW,237 HIGH,65 LOW,162 HIGH,96 LOW,136 HIGH,185 LOW,158 HIGH,80 LOW,152 HIGH,184 LOW,72 HIGH,135 LOW,295 HIGH,67 LOW,4139 HIGH,917 LOW,217 HIGH,65 LOW,9642 HIGH,914 LOW,219 HIGH,66 LOW"
  b_battery_1 = a_battery_1.split(",")
  
  print "b_battery => ", b_battery_1.length
  print "\n"

  puts
  
  #########################
  # battery: 2
  #########################
  puts "************* battery: 2 *************"
  
  a_battery_2 = "707003 HIGH,916 LOW,439 HIGH,62 LOW,164 HIGH,68 LOW,159 HIGH,65 LOW,50 HIGH,68 LOW,159 HIGH,68 LOW,47 HIGH,68 LOW,48 HIGH,68 LOW,159 HIGH,65 LOW,50 HIGH,65 LOW,50 HIGH,66 LOW,50 HIGH,77 LOW,267 HIGH,68 LOW,56 HIGH,173 LOW,98 HIGH,135 LOW,272 HIGH,66 LOW,69 HIGH,136 LOW,136 HIGH,152 LOW,237 HIGH,68 LOW,159 HIGH,95 LOW,136 HIGH,185 LOW,158 HIGH,80 LOW,152 HIGH,184 LOW,71 HIGH,135 LOW,297 HIGH,67 LOW,4140 HIGH,916 LOW,217 HIGH,63 LOW,"
  b_battery_2 = a_battery_2.split(",")
  
  print "b_battery => ", b_battery_2.length
  print "\n"

  puts
  
  #########################
  # battery: 3
  #########################
  puts "************* battery_3 *************"
  
  a_battery_3 = "11522618 HIGH,914 LOW,441 HIGH,62 LOW,164 HIGH,65 LOW,161 HIGH,66 LOW,50 HIGH,66 LOW,161 HIGH,65 LOW,51 HIGH,65 LOW,51 HIGH,65 LOW,162 HIGH,64 LOW,50 HIGH,65 LOW,50 HIGH,65 LOW,50 HIGH,77 LOW,266 HIGH,65 LOW,59 HIGH,173 LOW,98 HIGH,135 LOW,271 HIGH,66 LOW,71 HIGH,135 LOW,136 HIGH,152 LOW,237 HIGH,66 LOW,161 HIGH,96 LOW,136 HIGH,182 LOW,162 HIGH,80 LOW,152 HIGH,181 LOW,74 HIGH,135 LOW,295 HIGH,65 LOW,4141 HIGH,916 LOW,217 HIGH,66 LOW"
  b_battery_3 = a_battery_3.split(",")
  
  print "b_battery => ", b_battery_3.length
  print "\n"

  puts
  
  #########################
  # battery: 4
  #########################
  puts "************* battery_4 *************"
  
  a_battery_4 = "372873,912,442,62,164,65,162,65,51,65,162,65,50,66,50,66,162,65,51,64,50,65,51,65,50,65,161,65,51,65,51,65,50,65,161,66,161,65,50,66,162,65,162,65,162,65,161,65,50,65,51,65,50,66,162,65,51,65,51,65,51,65,50,65,162,65,162,65,4142,914,220,62"
  b_battery_4 = a_battery_4.split(",")
  
  print "b_battery => ", b_battery_4.length
  print "\n"

  puts
  
end#def execute_3

execute_s5_1
#execute_3
#execute_2
#execute
