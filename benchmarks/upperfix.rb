require 'benchmark'
require 'greek_string_utils'

if RUBY_ENGINE == 'ruby'
  require 'pry'
end

include GreekStringUtils

file = File.expand_path('../example.txt', __FILE__)
text = IO.read(file)

Benchmark.bmbm(7) do |x|
  iterations = 1000

  x.report('build-in Ruby #upcase implementation') do
    iterations.times do |i|
      text.upcase
    end
  end

  x.report('#upperfix C extension implementation') do
    iterations.times do |i|
      upperfix(text)
    end
  end

  x.report('#upperfix Ruby implementation') do
    iterations.times do |i|
      upperfix_rb(text)
    end
  end
end
