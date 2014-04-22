# Initial conditions
Conditions = OpenStruct.new(
  :starting_toughness =>  10,
  :starting_hp        =>  10,
  :starting_exp       =>   0,
  :starting_level     =>   1,
  :starting_exp_next  => 100,
)
Rules = OpenStruct.new(
  # Game data
  :turns            => 1e2, # Game turns

  # Combat & opponents
  :turns_per_combat =>  20,          # Poisson mean of combats
  :opponent_hp_ratio => 0.8,         # Times the hp of the player
  :opponent_toughness_ratio => 0.9,  # Times the toughness of the player

  # Autoheal
  :heal_toughness_ratio => 0.1,     # Times the toughness of the player bonus to hp, set to 0 to disable
  :turns_per_heal   =>  5,          # Number of turns before auto heals

  # Levelling
  :exp_next_level_multiplier => 1.5, # Experience curve
  :exp_next_level_power      => 1.01,

  :exp_toughness_ratio       => 0.01, # The experience gained by kill depends on the opponents toughness
  :exp_toughness_multiplier  => 100, # This could be included in the ratio, separated for clarity (to keep the ratio and toughness in 0..1 and in the same 'units')

  :levelup_toughness_multiplier => 1.1,  # Player toughness bonus
  :levelup_hp_multiplier        => 1.25, # Player hp bonus
  :levelup_heal                 => true,
)
