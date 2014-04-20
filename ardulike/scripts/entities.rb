Player = Struct.new(:toughness, :hp, :hp_max, :exp, :exp_next_level, :level, :hp_mean, :kills, :died_in_turn) do
  def to_s
    "[#{self.class.name.downcase}] lvl: #{level} exp: #{exp}/#{exp_next_level} toughness: #{toughness} hp: #{hp}/#{hp_mean}/#{hp_max} kills: #{kills} #{"died: #{died_in_turn}" if died_in_turn}"
  end
end

Npc = Struct.new(:toughness, :hp, :hp_max, :exp, :exp_next_level, :level) do
  def to_s
    "[#{self.class.name.downcase}] lvl: #{level} exp: #{exp}/#{exp_next_level} toughness: #{toughness} hp: #{hp}/#{hp_max}"
  end
end
