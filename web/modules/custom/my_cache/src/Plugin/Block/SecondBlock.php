<?php

namespace Drupal\my_cache\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Cache\Cache;

/**
 * Provides a 'DefaultBlock' block.
 *
 * @Block(
 *  id = "second_block",
 *  admin_label = @Translation("Second block"),
 * )
 */
class SecondBlock extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function build() {
    $count = rand(1,10);
    $build = [
      '#theme' => 'my_cache',
      '#name' => $count,
      /*'#cache' => [
        //'keys' => ['special-key-for-block-second'],
        //'contexts' => ['url.path']

      ],*/
    ];


    return $build;
  }


  public function getCacheMaxAge() {
    return Cache::mergeMaxAges(parent::getCacheMaxAge(), 0);
  }

}
