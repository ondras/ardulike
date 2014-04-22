def combat(x, y)
  attack  = [[normal(x.toughness, x.toughness / 3.0), 0].max, 2 * x.toughness].min
  defense = [[normal(y.toughness, y.toughness / 3.0), 0].max, 2 * y.toughness].min
  dmg     = [(attack - defense).to_i, 0].max
  y.hp   -= dmg
end

def levelup(player, rules)
  player.exp_next_level = ((player.exp_next_level * rules.exp_next_level_multiplier) ** rules.exp_next_level_power).to_i
  player.hp_max = (player.hp_max * rules.levelup_hp_multiplier).to_i
  player.toughness = (player.toughness * rules.levelup_toughness_multiplier).to_i
  player.level += 1

  player.hp = player.hp_max if rules.levelup_heal
end

def gainexp(player, opponent, rules)
  d_exp = (opponent.toughness * rules.exp_toughness_ratio * rules.exp_toughness_multiplier).to_i
  while player.exp + d_exp > player.exp_next_level
    d_exp -= (player.exp_next_level - player.exp)
    levelup(player, rules)
  end
  player.exp += d_exp
end

def heal(player, rules)
  player.hp = [player.hp + (rules.heal_toughness_ratio * player.toughness).to_i, player.hp_max].min;
end

def generate_opponent(player, rules)
  opponent            = Npc.new(
    (player.toughness * rules.opponent_toughness_ratio).to_i,
    (player.hp_max * rules.opponent_hp_ratio).to_i,
    (player.hp_max * rules.opponent_hp_ratio).to_i,
    player.exp,
    player.exp_next_level,
    player.level
  )
end

