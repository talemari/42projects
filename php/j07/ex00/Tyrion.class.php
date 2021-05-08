<?php
    class Tyrion extends Lannister
    {
        public function getSize() {
            echo "My name is " , get_class($this), "\n";
            return "Short";
        }
    }
?>
