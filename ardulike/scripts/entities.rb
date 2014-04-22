Player = Struct.new(:toughness, :hp, :hp_max, :exp, :exp_next_level, :level, :hp_mean, :kills, :deaths, :died_in_turn) do
  def to_s
    "[#{self.class.name.downcase}] lvl: #{level} exp: #{exp}/#{exp_next_level} toughness: #{toughness} hp: #{hp}/#{(hp_mean * 100).to_i / 100.0}/#{hp_max} kills: #{kills} deaths: #{deaths} #{"died: #{died_in_turn}" if died_in_turn}"
  end
end

Npc = Struct.new(:toughness, :hp, :hp_max, :exp, :exp_next_level, :level) do
  def to_s
    "[#{self.class.name.downcase}] lvl: #{level} exp: #{exp}/#{exp_next_level} toughness: #{toughness} hp: #{hp}/#{hp_max}"
  end
end
