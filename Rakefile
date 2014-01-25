require 'bundler/gem_tasks'
require 'rake/extensiontask'

gem_name = 'greek_string_utils'
spec = Gem::Specification.load("#{gem_name}.gemspec")

Rake::ExtensionTask.new do |ext|
  ext.name = 'upperfix'
  ext.ext_dir = "ext/#{gem_name}"
  ext.lib_dir = "lib/#{gem_name}"
  ext.gem_spec = spec
end
