#include "../SDP_Solver_Parameters.hxx"

std::ostream &operator<<(std::ostream &os, const SDP_Solver_Parameters &p)
{
  os << "SDP directory   : " << p.sdp_directory << '\n'
     << "out directory   : " << p.out_directory << '\n'
     << "checkpoint in   : " << p.checkpoint_in << '\n'
     << "checkpoint out  : " << p.checkpoint_out << '\n'
     << "\nParameters:\n"
     << std::boolalpha << "maxIterations                = " << p.max_iterations
     << '\n'
     << "maxRuntime                   = " << p.max_runtime << '\n'
     << "checkpointInterval           = " << p.checkpoint_interval << '\n'
     << "noFinalCheckpoint            = " << p.no_final_checkpoint << '\n'
     << "writeSolution                = " << p.write_solution << '\n'
     << "findPrimalFeasible           = " << p.find_primal_feasible << '\n'
     << "findDualFeasible             = " << p.find_dual_feasible << '\n'
     << "detectPrimalFeasibleJump     = " << p.detect_primal_feasible_jump
     << '\n'
     << "detectDualFeasibleJump       = " << p.detect_dual_feasible_jump
     << '\n'
     << "precision(actual)            = " << p.precision << "("
     << mpf_get_default_prec() << ")" << '\n'

     << "dualityGapThreshold          = " << p.duality_gap_threshold << '\n'
     << "primalErrorThreshold         = " << p.primal_error_threshold << '\n'
     << "dualErrorThreshold           = " << p.dual_error_threshold << '\n'
     << "initialMatrixScalePrimal     = " << p.initial_matrix_scale_primal
     << '\n'
     << "initialMatrixScaleDual       = " << p.initial_matrix_scale_dual
     << '\n'
     << "feasibleCenteringParameter   = " << p.feasible_centering_parameter
     << '\n'
     << "infeasibleCenteringParameter = " << p.infeasible_centering_parameter
     << '\n'
     << "stepLengthReduction          = " << p.step_length_reduction << '\n'
     << "maxComplementarity           = " << p.max_complementarity << '\n'
     << "procsPerNode                 = " << p.procs_per_node << '\n'
     << "procGranularity              = " << p.proc_granularity << '\n'
     << "verbosity                    = " << static_cast<int>(p.verbosity)
     << '\n';
  return os;
}
