<?php


namespace Drupal\view_tutorial_fruit\Plugin\views\argument_validator;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\argument_validator\ArgumentValidatorPluginBase;

/**
 * Validate whether an argument is a number that ends with a given substring.
 *
 * @ViewsArgumentValidator(
 *   id = "string_label_validator",
 *   title = @Translation("String Label Validator")
 * )
 */
class StringLabelValidator extends ArgumentValidatorPluginBase
{

  public function defineOptions()
  {
    return parent::defineOptions(); // TODO: Change the autogenerated stub
  }

  public function validateArgument($arg)
  {
    return ctype_alpha($arg);
  }
}
