<?php

namespace Drupal\hello_world\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\hello_world\HelloWorldSalutationInterface;
use Drupal\node\NodeInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Class HelloWorldController.
 */
class HelloWorldController extends ControllerBase {


  /**
   * @var \Drupal\hello_world\HelloWorldSalutationInterface
   */
  private $helloWorldSalutation;

  public function __construct(HelloWorldSalutationInterface $helloWorldSalutation) {
    $this->helloWorldSalutation = $helloWorldSalutation;
  }

  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('hello_world.salutation')
    );
  }

  /**
   * Helloworld.
   *
   * @return string
   *   Return Hello string.
   */
  public function helloWorld(NodeInterface $node) {
    dump($node); die();
    return [
      '#type' => 'markup',
      '#markup' => $this->t('Implement method: helloWorld')
    ];
  }

  public function helloWorldSimple() {
    return [
      '#type' => 'markup',
      '#markup' => $this->helloWorldSalutation->getSalutation()
    ];
  }
}
