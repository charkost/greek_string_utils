# coding: utf-8
require 'greek_string_utils/upperfix'

module GreekStringUtils
  def upperfix_rb(string)
    string.to_s.chars.map do |char|
      case char
      # Downcase characters
      when 'α' then 'Α'
      when 'β' then 'Β'
      when 'γ' then 'Γ'
      when 'δ' then 'Δ'
      when 'ε' then 'Ε'
      when 'ζ' then 'Ζ'
      when 'η' then 'Η'
      when 'θ' then 'Θ'
      when 'ι' then 'Ι'
      when 'κ' then 'Κ'
      when 'λ' then 'Λ'
      when 'μ' then 'Μ'
      when 'ν' then 'Ν'
      when 'ξ' then 'Ξ'
      when 'ο' then 'Ο'
      when 'π' then 'Π'
      when 'ρ' then 'Ρ'
      when 'σ' then 'Σ'
      when 'ς' then 'Σ'
      when 'τ' then 'Τ'
      when 'υ' then 'Υ'
      when 'φ' then 'Φ'
      when 'χ' then 'Χ'
      when 'ψ' then 'Ψ'
      when 'ω' then 'Ω'
      # Downcase characters with acute accents
      when 'ά' then 'Α'
      when 'έ' then 'Ε'
      when 'ή'
        string.to_s.size > 1 ? 'H' : 'Ή'
      when 'ί' then 'Ι'
      when 'ό' then 'Ο'
      when 'ύ' then 'Υ'
      when 'ώ' then 'Ω'
      # Upcase characters with acute accents
      when 'Ά' then 'Α'
      when 'Έ' then 'Ε'
      when 'Ή' then 'Η'
      when 'Ί' then 'Ι'
      when 'Ό' then 'Ο'
      when 'Ύ' then 'Υ'
      when 'Ώ' then 'Ω'
      # Downcase characters with acute and diaeresis accents (diaeresis preserved in upcase)
      when 'ϊ' then 'Ϊ'
      when 'ϋ' then 'Ϋ'
      # Downcase characters with acute and diaeresis accents (diaeresis preserved in upcase)
      when 'ΐ' then 'Ϊ'
      when 'ΰ' then 'Ϋ'
      else char.upcase
      end
    end.join
  end

  def remove_accents(string)
   string.to_s.chars.map do |char|
      case char
      when 'ά' then 'α'
      when 'έ' then 'ε'
      when 'ή' then 'η'
      when 'ί' then 'ι'
      when 'ό' then 'ο'
      when 'ύ' then 'υ'
      when 'ώ' then 'ω'
      when 'Ά' then 'Α'
      when 'Έ' then 'Ε'
      when 'Ή' then 'Η'
      when 'Ί' then 'Ι'
      when 'Ϊ' then 'Ι'
      when 'Ό' then 'Ο'
      when 'Ύ' then 'Υ'
      when 'Ώ' then 'Ω'
      when 'ϊ' then 'ι'
      when 'ϋ' then 'υ'
      when 'ΐ' then 'ι'
      when 'ΰ' then 'υ'
      else char
      end
    end.join
  end

  def has_accent?(string)
    string.to_s.match(/ά|έ|ή|ί|ό|ύ|ώ|Ά|Έ|Ή|Ί|Ϊ|Ό|Ύ|Ώ|ϊ|ϋ|ΐ|ΰ/) ? true : false
  end

  def greek_sort(array)
    array.sort do |a, b|
      x = remove_accents(a)
      y = remove_accents(b)

      x == y ?  a <=> b : x <=> y
    end
  end
end
