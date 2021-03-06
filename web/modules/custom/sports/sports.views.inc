<?php

/**
 * @file
 * Contains my_module_view_field\my_module_view_field.views.inc..
 * Provide a custom views field data that isn't tied to any other module.
 *
 */


/**
* Implements hook_views_data().
*/
function sports_views_data() {

  $views_data = [];
  $views_data['teams']['table'] = [
    'group' => t('Team.'),
    'base' => [
      'field' => 'id',
      'title' => t('Team'),
      'help' => t('Team Table available by Team .'),
    ]
  ];

  $views_data['players']['table'] = [
    'title' => t('Players Table'),
    'group' => t('Players.'),
    'base' => [
      'field' => 'id',
      'title' => t('Players'),
      'help' => t('Players Table available by Team .'),
    ],
    'join' => [
      'team' => [
        'left_field' => 'id',
        'field' => 'team_id',
      ]
    ]
  ];

  $views_data['players']['id'] = [
    'title' => t('Players ID'),
    'help' => t('ID of the player.'),
    'field' => [
      'id' => 'numeric',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'in_operator',
    ],

  ];

  $views_data['teams']['id'] = [
    'title' => t('Teams ID'),
    'help' => t('ID of the team.'),
    'field' => [
      'id' => 'numeric',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'in_operator',
    ],
    'argument' => [
      'id' => 'standard',
    ],

  ];

  $views_data['teams']['name'] = [
    'title' => t('Team Name Column'),
    'help' => t('Name of the team.'),

    'field' => [
      'id' => 'standard',
    ],
    // So let's tell Views sorting by this column is actually possible.
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'team_filter',
    ],

  ];

  /*$views_data['teams']['my_name'] = array(
    'title' => t('My specify name'),
    'filter' => array(
      'title' => t('My specify name'),
      'help' => t('Specify name.'),
      'field' => 'name',
      'id' => 'in_operator'
    ),
  );*/

  $views_data['teams']['description'] = [
    'title' => t('Teams description'),
    'help' => t('Description of the team.'),
    'field' => [
      'id' => 'standard',
    ],
    'sort' => [
      'id' => 'string',
    ],
    'filter' => [
      'id' => 'string',
    ],

  ];

  $views_data['teams']['status'] = [
    'title' => t('Teams status'),
    'help' => t('Status of the team.'),
    'field' => [
      'id' => 'standard',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'boolean',
    ],

  ];

  $views_data['teams']['team'] = array(
    'title' => t('Team'),
    'help' => t('The team (either an ID or a team name).'),
    'argument' => array(
      'id' => 'team',
    ),
  );

  /**
   * Relationship
   */
  $views_data['players']['team_id'] = [
    'title' => t('Team ID'),
    'help' => t('The unique team ID of the player.'),
    'field' => array(
      'id' => 'numeric',
    ),
    'argument' => array(
      'id' => 'numeric',
    ),
    'relationship' => [
      'id' => 'standard',
      'base' => 'teams',
      'base field' => 'id',
      'label' => t('Relation to {team.id}'),

    ],
  ];


  $views_data['players']['name'] = [
    'title' => t('Player Name'),
    'help' => t('The player name.'),
    'field' => [

      'id' => 'standard',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'string',
    ],

  ];

  $views_data['players']['data'] = [
    'title' => t('Data field'),
    'help' => t('Serialized Data field'),
    'field' => [
      'id' => 'serialized'
    ]
  ];

  return $views_data;
}
