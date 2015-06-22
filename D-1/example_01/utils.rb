#!C:\WORKS\Programs\Ruby22-x64\bin\ruby.exe

require 'pathname'

#REF nil https://www.ruby-forum.com/topic/163142 2008-08-19 10:23
def build_Method_List(fpath_in, fpath_Out = nil)
#def build_Method_List(fpath_in, fpath_Out = null)
  
  # build output path
  if fpath_Out == nil

    # use => fpath_in string
    fpath_Out = fpath_in + ".METHODS"
    
    #########################
    # build: out path
    #########################
    
    
    
#    #REF http://ruby-doc.org/stdlib-2.1.0/libdoc/pathname/rdoc/Pathname.html
##    #test
##    tmp = fpath_in + ".abc.def"
#
#    #REF http://stackoverflow.com/questions/374326/get-filename-without-extension-from-file-path-in-ruby answered Dec 17 '08 at 12:27      
##    path = Pathname.new(tmp)
#    path = Pathname.new(fpath_in)
#
#    # get: dir, base    
#    dir, base = path.split
#    
#    puts "dir = #{dir} | base = #{base}"
#    
#    # split: basename
#    #REF split http://stackoverflow.com/questions/1333347/how-to-use-stringsplit-in-ruby answered Aug 26 '09 at 9:10
#    tokens = base.to_s.split(/\./)
##    tokens = base.string.split(/\./) #=> n/w
##    tokens = base.split(/\./) #=> n/w
#    
#    # trunk and extension of the input file path
#    trunk = ""; ext = ""
#    
##    #debug
##    puts tokens.join("+++")
#    
#    if tokens == nil or tokens.size == 1
#      
#      trunk = fpath_in
#      ext = ""
#      
#    elsif tokens.size == 2
#      
#      trunk = tokens[0]
#      ext = tokens[1]
#      
#    elsif tokens.size > 2
#      
#      trunk = tokens[0..-2].join("/")
#      ext = tokens[-1]
#      
#    end
#    
#    puts "trunk = #{trunk} | ext = #{ext}"
#
#    # build: output path
#    #REF join http://stackoverflow.com/questions/4402336/ruby-array-join-versus-string-concatenation-efficiency
##    fpath_Out = Array.new(trunk, ".METHODS.", ext).join("/")
##    fpath_Out = Array.new(3){trunk, ".METHODS.", ext}
##    fpath_Out = Array({trunk, "METHODS", ext})
##    fpath_Out = [{trunk, "METHODS", ext}]  #=> n/w
#    fpath_Out = [trunk, ".METHODS.", ext]
#    
#    puts "fpath_Out = #{fpath_Out.join}"
##    puts "fpath_Out = #{fpath_Out}"
#              
#    
###    puts "fpath_Out == nil"
#        
#    tokens = fpath_in.split(/\./)
#    
#    # get basename
#    path = Pathname.new(fpath_in)
#    
#    puts path.basename
##    puts Pathname.new(fpath_in).basename
#    
#    puts path.methods.sort
#    
##    puts tokens
##    fpath_Out = 
    
#  else#if fpath_Out == nil
    
  end#if fpath_Out == nil
  
  
  # open file
  f_in = File.open(fpath_in, "r")
  f_Out = File.open(fpath_Out, "w")
  
  #REF gets http://www.abbeyworkshop.com/howto/ruby/rb-readfile/index.html
  line = f_in.gets
  
  #REF multiple http://stackoverflow.com/questions/5239997/regex-how-to-match-multiple-lines answered Mar 9 '11 at 0:36
#  pattern = /void (.+)(\(.*\)) {.+;\r\n}/m #=> n/w
#  pattern = /void (.+)(\(.*\)) {.+}/m #=> n/w
#  pattern = /void (.+)(\(.*\)) {[.\r\n;]+}/
  pattern = /void (.+)(\(.*\)) {/
#  pattern = /void (.+)\(.*\) {/
  
  methods = Array.new
  
  while(line)
    
    res = (line=~ pattern)
    
    match = line.match pattern
    
    if res
      
      puts "res => #{res}"
      
    end
    
    if match
      
      puts "match => " + match.string + "/" + "match[1] = #{match[1]}"\
            + "/" + "match.size => "  + match.size.to_s
#            + "match.size => #{match.size}"
 
#      f_Out.write(match[1] + "\n")
      
      methods << match[1] + match[2]
#      methods << line
                 
    end
    
    #REF gets http://www.abbeyworkshop.com/howto/ruby/rb-readfile/index.html
    line = f_in.gets
    
  end#while(line)
  
  #########################
  # close files: input file
  #########################
  f_in.close
#  f_Out.close
  
  #########################
  # write: output
  #########################
  # sort
  methods.sort!
  
  methods.each do |m|
    
    f_Out.write(m + "\n")
    
  end
  
  #########################
  # close files: input file
  #########################
  f_Out.close
  
  
#  line = f_in.gets
#  
#  print line
  
end

def execute

#  fpath_in = "C:/WORKS/WS/WS_Arduino/D-1/example_01/example_01.ino.abc.def"
  fpath_in = "C:/WORKS/WS/WS_Arduino/D-1/example_01/example_01.ino"
  
  build_Method_List(fpath_in)
    
end

execute

