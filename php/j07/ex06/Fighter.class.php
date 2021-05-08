<?php 
    abstract class Fighter {
        private $type;
        public function __construct($fighter) {
            $this->type = $fighter;
        }
        public function getType() {
            return $this->type;
        }
        abstract function fight($fighter);
    }
?>