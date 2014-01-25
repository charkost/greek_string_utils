$:.push File.expand_path("../lib", __FILE__)

# Maintain your gem's version:
require "greek_string_utils/version"

# Describe your gem and declare its dependencies:
Gem::Specification.new do |s|
  s.name        = "greek_string_utils"
  s.version     = GreekStringUtils::VERSION
  s.authors     = ["Giorgos Tsiftsis"]
  s.email       = ["giorgos.tsiftsis@gmail.com"]
  s.homepage    = "https://github.com/chief/greek_string_utils"
  s.summary     = "Simple library to correct upcase in greek"
  s.description = "Simple library to correct upcase in greek"

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ['lib']

  s.extensions << "ext/#{s.name}/extconf.rb"

  s.add_development_dependency 'rspec'
  s.add_development_dependency 'rake-compiler'

  if RUBY_ENGINE == "ruby"
    if RUBY_VERSION > "1.9.3"
      s.add_development_dependency "pry-byebug", "~> 1.2.1"
    else
      s.add_development_dependency "pry", "~> 0.9.12.4"
    end
  end
end
