#!C:\WORKS\Programs\Ruby22-x64\bin\ruby.exe

require 'pathname'

#REF nil https://www.ruby-forum.com/topic/163142 2008-08-19 10:23
def build_Method_List(fpath_in, fpath_Out = nil)
  
  #########################
  # build: out path
  #########################
  if fpath_Out == nil

    # use => fpath_in string
    fpath_Out = fpath_in + ".METHODS"
    
  end#if fpath_Out == nil

  #########################
  # build: methods list
  #########################
  # open file
  f_in = File.open(fpath_in, "r")
  
  #REF gets http://www.abbeyworkshop.com/howto/ruby/rb-readfile/index.html
  line = f_in.gets

  # pattern (if multiple, add 'm' after the right hand of '/' char)
  #   what to detect => 1) method name, 2) parameters   
  #REF multiple http://stackoverflow.com/questions/5239997/regex-how-to-match-multiple-lines answered Mar 9 '11 at 0:36
  pattern = /void (.+)(\(.*\)) {/

  # array for method strings  
  methods = Array.new
  
  # read lines
  while(line)
    
    res = (line=~ pattern)
    
    match = line.match pattern
    
    # match?
    if match

      # push matched strings into the array      
      methods << match[1] + "\t" + match[2]
#      methods << match[1] + match[2]
                 
    end
    
    # next line
    #REF gets http://www.abbeyworkshop.com/howto/ruby/rb-readfile/index.html
    line = f_in.gets
    
  end#while(line)
  
  #########################
  # close files: input file
  #########################
  f_in.close
  
  #########################
  # write: output
  #########################
  # open file
  f_Out = File.open(fpath_Out, "w")

  # sort: use '!' for destructive effect
  methods.sort!
  
  # counter
  counter = 0
  
  # write each method string (with a new-line char '\n')
  methods.each_with_index do |m, i|
    
    f_Out.write("#{i + 1}.\t#{m}" + "\n")
#    f_Out.write(m + "\n")
    
    counter = counter + 1
    
  end
  
  #########################
  # close files: input file
  #########################
  f_Out.close
  
  #########################
  # return
  #########################
  return counter
  
end#build_Method_List(fpath_in, fpath_Out = nil)

def execute

#  fpath_in = "C:/WORKS/WS/WS_Arduino/D-1/example_01/example_01.ino.abc.def"
  fpath_in = "C:/WORKS/WS/WS_Arduino/D-1/example_01/example_01.ino"
  
  res = build_Method_List(fpath_in)
  
  printf("done: res = %d", res)
    
end

execute

