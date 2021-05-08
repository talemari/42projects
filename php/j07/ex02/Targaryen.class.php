<?php 
    class Targaryen {
        public function getBurned() {
            if (get_class($this) == "Daenerys")
            {
                return ("emerges naked but unharmed");   
            }
            else 
                return ("burns alive");
        }
    }
?>